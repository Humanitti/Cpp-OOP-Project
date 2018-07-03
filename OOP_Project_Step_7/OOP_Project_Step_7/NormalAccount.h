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
		Account::Deposit(money); // ���� �߰�
		Account::Deposit((int)(money*(basicRate / 100.0))); // ���� �߰�
	}

	virtual void ShowAccountInfo() const
	{
		cout << "[���뿹�ݰ���]\n";
		cout << "����ID: " << GetAccID() << '\n';
		cout << "��  ��: " << GetName() << '\n';
		cout << "��  ��: " << GetBalance() << "��\n";
		cout << "������: " << basicRate << "%\n";
	}
};