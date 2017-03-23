#include <iostream>
#include "bank-account.h"
#include "bank.h"

using std::cout;

void testConstructors() {
  BankAccount emptyBankAccount;
  emptyBankAccount.print();

  BankAccount bankAccountWithNoMoney("Petar", "10AC9D2C");
  bankAccountWithNoMoney.print();

  BankAccount bankAccount("Georgi", "V7RG42NR", 2481.42);
  bankAccount.print();
}

void testDepositAndDraw() {
  BankAccount bankAccount("Georgi", "V7RG42NR");
  bankAccount.print();

  bankAccount.deposit(100);
  bankAccount.print();

  bankAccount.draw(70);
  bankAccount.print();
}

void testBank() {
  BankAccount accountOfIvan("Ivan", "1", 2000);
  BankAccount accountOfPetar("Petar", "2", 500);
  BankAccount secondAccountOfIvan("Ivan", "3", 400);

  BankAccount accounts[] = {accountOfIvan, accountOfPetar};
  Bank bank(accounts, 2);
  bank.addAccount(secondAccountOfIvan);

  cout << bank.getAccountBalance("2") << '\n';
  bank.removeAccount("2");

  cout << bank.getClientBalance("Ivan") << '\n';
}

int main() {
  testConstructors();
  testDepositAndDraw();
  testBank();

  return 0;
}