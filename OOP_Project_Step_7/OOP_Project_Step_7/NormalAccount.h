#pragma once
#include "Account.h"
#include "BankingCommonDecl.h"

class NormalAccount :
	public Account {
private:
	int basicRate;
public:
	NormalAccount(int accID, const char* name, int balance, int basicRate)
		: Account(accID, name, balance), basicRate(basicRate)
	{
	}
	int GetBasicRate() const { return basicRate; }
	virtual void Deposit(int money)
	{
		Account::Deposit(money); // 원금 추가
		Account::Deposit((int)(money*(basicRate / 100.0))); // 이자 추가
	}

	virtual void ShowAccountInfo() const
	{
		cout << "[보통예금계좌]\n";
		cout << "계좌ID: " << GetAccID() << '\n';
		cout << "이  름: " << GetName() << '\n';
		cout << "잔  액: " << GetBalance() << "원\n";
		cout << "이자율: " << basicRate << "%\n";
	}
};