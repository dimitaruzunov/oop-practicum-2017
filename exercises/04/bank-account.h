#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

class BankAccount {
  char clientName[30];
  char number[15];
  double balance;

public:

  BankAccount();

  BankAccount(const char* clientName, const char* number);

  BankAccount(const char* clientName, const char* number, double balance);

  const char* getClientName() const;

  const char* getNumber() const;

  double getBalance() const;

  void setClientName(const char* newClientName);

  void setNumber(const char* newNumber);

  void setBalance(double newBalance);

  void deposit(double amount);

  void draw(double amount);

  void print() const;
};

#endif
