#include "Account.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;

Account::Account(int accID, const char* name, int balance)
	: accID(accID), balance(balance)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

Account::Account(const Account& account)
{
	name = new char[strlen(account.name) + 1];
	strcpy_s(name, strlen(name) + 1, account.name);
}

Account::~Account()
{
	delete[] name;
}

int Account::GetAccID() const { return accID; }
char* Account::GetName() const { return name; }
int Account::GetBalance() const { return balance; }

void Account::Deposit(int money) { balance += money; }
int Account::Withdraw(int money) { if(balance < money) return 0; else balance -= money; return 1; }

void Account::ShowAccountInfo() const
{
	cout << "°èÁÂID: " << accID << '\n';
	cout << "ÀÌ  ¸§: " << name << '\n';
	cout << "ÀÜ  ¾×: " << balance << "¿ø\n";
}