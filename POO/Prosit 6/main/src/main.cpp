#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cctype>
#include <cmath>
#include <stdexcept>

//
// 1) TOKEN TYPES
//
enum class TokenType {
    Number,
    Identifier,
    Plus, Minus, Mul, Div, Pow,
    LParen, RParen,
    End
};

//
// 2) TOKEN CLASS
//
class Token {
public:
    TokenType type;
    std::string value;

    Token(TokenType t, std::string v = "")
        : type(t), value(std::move(v)) {}
};

//
// 3) TOKENIZER
//
class Tokenizer {
private:
    std::string text;
    size_t pos;

public:
    explicit Tokenizer(const std::string& input)
        : text(input), pos(0) {}

    std::vector<Token> tokenize() {
        std::vector<Token> tokens;

        while (pos < text.size()) {
            char c = text[pos];

            if (isspace(c)) { pos++; continue; }

            if (isdigit(c) || c == '.') {
                tokens.push_back(readNumber());
                continue;
            }

            if (isalpha(c)) {
                tokens.push_back(readIdentifier());
                continue;
            }

            switch (c) {
                case '+': tokens.emplace_back(TokenType::Plus); pos++; break;
                case '-': tokens.emplace_back(TokenType::Minus); pos++; break;
                case '*': tokens.emplace_back(TokenType::Mul); pos++; break;
                case '/': tokens.emplace_back(TokenType::Div); pos++; break;
                case '^': tokens.emplace_back(TokenType::Pow); pos++; break;
                case '(': tokens.emplace_back(TokenType::LParen); pos++; break;
                case ')': tokens.emplace_back(TokenType::RParen); pos++; break;
                default:
                    throw std::runtime_error(std::string("Caractère invalide : ") + c);
            }
        }

        tokens.emplace_back(TokenType::End);
        return tokens;
    }

private:
    Token readNumber() {
        size_t start = pos;
        bool hasPoint = false;

        while (pos < text.size() &&
               (isdigit(text[pos]) || text[pos] == '.')) {
            if (text[pos] == '.') {
                if (hasPoint) break;
                hasPoint = true;
            }
            pos++;
        }

        return Token(TokenType::Number, text.substr(start, pos - start));
    }

    Token readIdentifier() {
        size_t start = pos;
        while (pos < text.size() && isalpha(text[pos])) pos++;
        return Token(TokenType::Identifier, text.substr(start, pos - start));
    }
};

//
// 4) ABSTRACT SYNTAX TREE (AST)
//
class ASTNode {
public:
    virtual ~ASTNode() = default;
};

class NumberNode : public ASTNode {
public:
    double value;
    explicit NumberNode(double v) : value(v) {}
};

class UnaryNode : public ASTNode {
public:
    TokenType op;
    std::unique_ptr<ASTNode> expr;

    UnaryNode(TokenType op, std::unique_ptr<ASTNode> e)
        : op(op), expr(std::move(e)) {}
};

class BinaryNode : public ASTNode {
public:
    TokenType op;
    std::unique_ptr<ASTNode> left;
    std::unique_ptr<ASTNode> right;

    BinaryNode(TokenType op, std::unique_ptr<ASTNode> l, std::unique_ptr<ASTNode> r)
        : op(op), left(std::move(l)), right(std::move(r)) {}
};

class FunctionNode : public ASTNode {
public:
    std::string name;
    std::unique_ptr<ASTNode> arg;

    FunctionNode(std::string n, std::unique_ptr<ASTNode> a)
        : name(std::move(n)), arg(std::move(a)) {}
};

//
// 5) PARSER (recursive descent)
//
class Parser {
private:
    std::vector<Token> tokens;
    size_t pos;

public:
    explicit Parser(const std::vector<Token>& tokens)
        : tokens(tokens), pos(0) {}

    std::unique_ptr<ASTNode> parse() {
        return parseExpression();
    }

private:
    Token& current() { return tokens[pos]; }
    Token& eat() { return tokens[pos++]; }

    // Grammar:
    // expression = term (('+' | '-') term)*
    // term       = factor (('*' | '/') factor)*
    // factor     = exponent ('^' factor)?
    // exponent   = number | function | '(' expression ')' | unary
    // unary      = ('+' | '-') exponent

    std::unique_ptr<ASTNode> parseExpression() {
        auto node = parseTerm();

        while (current().type == TokenType::Plus ||
               current().type == TokenType::Minus) {
            TokenType op = current().type;
            eat();
            node = std::make_unique<BinaryNode>(op, std::move(node), parseTerm());
        }

        return node;
    }

    std::unique_ptr<ASTNode> parseTerm() {
        auto node = parseFactor();

        while (current().type == TokenType::Mul ||
               current().type == TokenType::Div) {
            TokenType op = current().type;
            eat();
            node = std::make_unique<BinaryNode>(op, std::move(node), parseFactor());
        }

        return node;
    }

    std::unique_ptr<ASTNode> parseFactor() {
        auto node = parseExponent();

        if (current().type == TokenType::Pow) {
            eat();
            node = std::make_unique<BinaryNode>(TokenType::Pow, std::move(node), parseFactor());
        }

        return node;
    }

    std::unique_ptr<ASTNode> parseExponent() {
        if (current().type == TokenType::Plus || current().type == TokenType::Minus) {
            TokenType op = current().type;
            eat();
            return std::make_unique<UnaryNode>(op, parseExponent());
        }

        if (current().type == TokenType::Number) {
            double val = std::stod(current().value);
            eat();
            return std::make_unique<NumberNode>(val);
        }

        if (current().type == TokenType::Identifier) {
            std::string name = current().value;
            eat();
            // Expect '('
            if (current().type != TokenType::LParen)
                throw std::runtime_error("Parenthèse attendue après fonction");

            eat();
            auto arg = parseExpression();
            if (current().type != TokenType::RParen)
                throw std::runtime_error("Parenthèse fermante manquante après argument de fonction");

            eat();
            return std::make_unique<FunctionNode>(name, std::move(arg));
        }

        if (current().type == TokenType::LParen) {
            eat();
            auto node = parseExpression();
            if (current().type != TokenType::RParen)
                throw std::runtime_error("Parenthèse fermante attendue");

            eat();
            return node;
        }

        throw std::runtime_error("Expression invalide");
    }
};

//
// 6) EVALUATOR
//
class Evaluator {
public:
    double eval(ASTNode* node) {
        if (auto n = dynamic_cast<NumberNode*>(node))
            return n->value;

        if (auto u = dynamic_cast<UnaryNode*>(node)) {
            double val = eval(u->expr.get());
            if (u->op == TokenType::Plus)  return +val;
            if (u->op == TokenType::Minus) return -val;
        }

        if (auto b = dynamic_cast<BinaryNode*>(node)) {
            double L = eval(b->left.get());
            double R = eval(b->right.get());

            switch (b->op) {
                case TokenType::Plus:  return L + R;
                case TokenType::Minus: return L - R;
                case TokenType::Mul:   return L * R;
                case TokenType::Div:   return L / R;
                case TokenType::Pow:   return std::pow(L, R);
                default: break;
            }
        }

        if (auto f = dynamic_cast<FunctionNode*>(node)) {
            double x = eval(f->arg.get());
            if (f->name == "sin")  return std::sin(x);
            if (f->name == "cos")  return std::cos(x);
            if (f->name == "tan")  return std::tan(x);
            if (f->name == "log")  return std::log(x);
            if (f->name == "sqrt") return std::sqrt(x);
            throw std::runtime_error("Fonction inconnue : " + f->name);
        }

        throw std::runtime_error("Noeud AST inconnu");
    }
};

//
// 7) MAIN pour tester
//
int main() {
    std::string expr = "3 + sqrt(16) * 2^3 - sin(3.14159/2)";

    Tokenizer tokenizer(expr);
    auto tokens = tokenizer.tokenize();

    Parser parser(tokens);
    auto ast = parser.parse();

    Evaluator evalExpr;
    std::cout << "Résultat = " << evalExpr.eval(ast.get()) << "\n";

    return 0;
}
