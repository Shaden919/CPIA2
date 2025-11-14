#include <string>
using namespace std;

#if !defined(DEF_BANKACCOUNT)
#define DEF_BANKACCOUNT

class BankAccount
{
private:
    string owner;
    double balance;
public:
    BankAccount(string owner,double balance = 0);
    ~BankAccount();
    void setBalance(double balance);
    void setOwner(string owner);
    double getBalance() const;
    string getOwner() const;
    bool deposit(double amount);
    bool take(double amount);
};



#endif // DEF_BANKACCOUNT
