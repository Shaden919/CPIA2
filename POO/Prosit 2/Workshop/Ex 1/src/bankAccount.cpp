#include "bankAccount.hpp"

BankAccount::BankAccount(string owner,double balance) {
    this->owner  = owner;
    this->balance = balance;
}
BankAccount::~BankAccount() {}

void BankAccount::setBalance(double balance) {
    this->balance = balance;
}
double BankAccount::getBalance() const {
    return this->balance;
}

void BankAccount::setOwner(string  owner) {
    this->owner = owner;
}

string BankAccount::getOwner() const {
    return this->owner;
}

bool BankAccount::deposit(double amount) {
    if(amount < 0) return false;
    this->balance += amount;
    return true;
}
bool BankAccount::take(double amount) {
    if(amount>this->balance) return false;
    this->balance -= amount;
    return true;
}
