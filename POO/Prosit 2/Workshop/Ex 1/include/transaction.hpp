#include "bankAccount.hpp"

#if !defined(DEF_TRANSACTION)
#define DEF_TRANSACTION

class Transaction
{
private:
   BankAccount* from;
   BankAccount* to;
   double amount;
public:
    Transaction(BankAccount* from,BankAccount* to,double amount);
    ~Transaction();
    string getFrom() const;
    string getTo() const;
    double getAmount() const;
    bool execute();
};


#endif // DEF_TRANSACTION

