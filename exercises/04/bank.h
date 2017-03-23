#ifndef BANK_H
#define BANK_H

#include "bank-account.h"

class Bank {
  BankAccount* bankAccounts;
  int size;
  int capacity;

  static const int INITIAL_CAPACITY;

  int findAccount(const char* number) const;

  void resize();

public:

  Bank();

  Bank(const BankAccount bankAccounts[], int bankAccountsCount);

  ~Bank();

  void addAccount(const BankAccount& bankAccount);

  void removeAccount(const char* number);

  double getAccountBalance(const char* number) const;

  double getClientBalance(const char* clientName) const;
};

#endif
