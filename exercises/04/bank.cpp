#include <algorithm>
#include "bank.h"

using std::max;

const int Bank::INITIAL_CAPACITY = 8;

Bank::Bank()
  : size(0), capacity(INITIAL_CAPACITY),
    bankAccounts(new BankAccount[capacity]) {}

Bank::Bank(const BankAccount* bankAccounts, int bankAccountsCount) {
  size = bankAccountsCount;
  capacity = max(size, INITIAL_CAPACITY);
  this->bankAccounts = new BankAccount[capacity];

  for (int i = 0; i < size; ++i) {
    this->bankAccounts[i].setClientName(bankAccounts[i].getClientName());
    this->bankAccounts[i].setNumber(bankAccounts[i].getNumber());
    this->bankAccounts[i].setBalance(bankAccounts[i].getBalance());
  }
}

Bank::~Bank() {
  delete[] bankAccounts;
}

void Bank::addAccount(const BankAccount& bankAccount) {
  if (size == capacity) {
    resize();
  }

  bankAccounts[size].setClientName(bankAccount.getClientName());
  bankAccounts[size].setNumber(bankAccount.getNumber());
  bankAccounts[size].setBalance(bankAccount.getBalance());

  ++size;
}

void Bank::removeAccount(const char* number) {
  int accountIndex = findAccount(number);

  if (accountIndex != -1) {
    for (int i = accountIndex; i < size - 1; ++i) {
      bankAccounts[i].setClientName(bankAccounts[i + 1].getClientName());
      bankAccounts[i].setNumber(bankAccounts[i + 1].getNumber());
      bankAccounts[i].setBalance(bankAccounts[i + 1].getBalance());
    }
  }

  --size;
}

double Bank::getAccountBalance(const char* number) const {
  int accountIndex = findAccount(number);

  if (accountIndex != -1) {
    return bankAccounts[accountIndex].getBalance();
  }

  return -1;
}

double Bank::getClientBalance(const char* clientName) const {
  double balance = 0;

  for (int i = 0; i < size; ++i) {
    if (strcmp(bankAccounts[i].getClientName(), clientName) == 0) {
      balance += bankAccounts[i].getBalance();
    }
  }

  return balance;
}

int Bank::findAccount(const char* number) const {
  for (int i = 0; i < size; ++i) {
    if (strcmp(bankAccounts[i].getNumber(), number) == 0) {
      return i;
    }
  }

  return -1;
}

void Bank::resize() {
  capacity *= 2;

  BankAccount* newBankAccounts = new BankAccount[capacity];

  for (int i = 0; i < size; ++i) {
    newBankAccounts[i].setClientName(bankAccounts[i].getClientName());
    newBankAccounts[i].setNumber(bankAccounts[i].getNumber());
    newBankAccounts[i].setBalance(bankAccounts[i].getBalance());
  }

  delete[] bankAccounts;

  bankAccounts = newBankAccounts;
}
