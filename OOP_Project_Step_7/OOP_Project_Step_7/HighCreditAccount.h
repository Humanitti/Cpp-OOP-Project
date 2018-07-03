#pragma once
#include "Account.h"
#include "NormalAccount.h"
#include "BankingCommonDecl.h"

class HighCreditAccount : public NormalAccount {
private:
	int creditRating;
public:
	HighCreditAccount(int accID, const char* name, int balance, int basicRate, int creditRating)
		: NormalAccount(accID, name, balance, basicRate), creditRating(creditRating)
	{
	}

	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money); // 원금, 이자 추가
		Account::Deposit((int)(money*(creditRating / 100.0))); // 특별이자 추가
	}

	virtual void ShowAccountInfo() const
	{
		cout << "[신용신뢰계좌]\n";
		cout << "계좌ID: " << GetAccID() << '\n';
		cout << "이  름: " << GetName() << '\n';
		cout << "잔  액: " << GetBalance() << "원\n";
		cout << "이자율: " << GetBasicRate() << "%\n";
		if(creditRating == LEV_A) cout << "신용등급: A(" << LEV_A << "%)\n";
		else if(creditRating == LEV_B) cout << "신용등급: B(" << LEV_B << "%)\n";
		else if(creditRating == LEV_C) cout << "신용등급: C(" << LEV_C << "%)\n";
	}
};