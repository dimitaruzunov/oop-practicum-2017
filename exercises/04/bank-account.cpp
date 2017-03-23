#include <cstring>
#include <iostream>
#include "bank-account.h"

using std::cout;

BankAccount::BankAccount(): clientName(""), number(""), balance(0) {}

BankAccount::BankAccount(const char* clientName, const char* number) {
  strcpy(this->clientName, clientName);
  strcpy(this->number, number);

  balance = 0;
}

BankAccount::BankAccount(const char* clientName, const char* number,
                         double balance) {
  strcpy(this->clientName, clientName);
  strcpy(this->number, number);

  this->balance = balance;
}

const char* BankAccount::getClientName() const {
  return clientName;
}

const char* BankAccount::getNumber() const {
  return number;
}

double BankAccount::getBalance() const {
  return balance;
}

void BankAccount::setClientName(const char* newClientName) {
  strcpy(clientName, newClientName);
}

void BankAccount::setNumber(const char* newNumber) {
  strcpy(number, newNumber);
}

void BankAccount::setBalance(double newBalance) {
  balance = newBalance;
}

void BankAccount::deposit(double amount) {
  balance += amount;
}

void BankAccount::draw(double amount) {
  balance -= amount;
}

void BankAccount::print() const {
  cout << clientName << ", " << number << ", " << balance << " leva\n";
}
