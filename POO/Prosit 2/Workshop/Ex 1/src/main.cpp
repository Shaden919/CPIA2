#include "bankAccount.hpp"
#include "transaction.hpp"
#include <iostream>
using namespace std;

int main() {
    BankAccount compte1("gabriel",1000);
    BankAccount compte2("louis",500);

    Transaction transact1(&compte1,&compte2,500);

    if (transact1.execute()) {
        cout << "transaction successful" << "\n";
    } else {cout << "transaction failed" <<"\n";}

    cout << compte1.getBalance() << endl;
    cout << compte2.getBalance() << endl;

    Transaction transact2(&compte1,&compte2,5000);    

    if (transact2.execute()) {
        cout << "transaction successful" << "\n";
    } else {cout << "transaction failed" <<"\n";}

    cout << compte1.getBalance() << endl;
    cout << compte2.getBalance() << endl;

    return 0;
}