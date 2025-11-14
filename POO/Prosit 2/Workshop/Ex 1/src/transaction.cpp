#include "transaction.hpp"
#include <iostream>

Transaction::Transaction(BankAccount* from,BankAccount* to,double amount) : from(from), to(to),amount(amount) {}
Transaction::~Transaction() {}
string Transaction::getFrom() const {
    return from->getOwner();
}
string Transaction::getTo() const {
    return to->getOwner();
}
double Transaction::getAmount() const {
    return this->amount;
}

bool Transaction::execute() {
    if (this->amount>from->getBalance()) {
        cout<< "pas asser de fonds depuis le compte crediteur" << "\n";
        return false;
    }
    from->take(amount);
    to->deposit(amount);
    return true;
}

