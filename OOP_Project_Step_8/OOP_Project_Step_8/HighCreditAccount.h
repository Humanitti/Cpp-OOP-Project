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
		NormalAccount::Deposit(money); // ����, ���� �߰�
		Account::Deposit((int)(money*(creditRating / 100.0))); // Ư������ �߰�
	}

	virtual void ShowAccountInfo() const
	{
		cout << "[�ſ�ŷڰ���]\n";
		cout << "����ID: " << GetAccID() << '\n';
		cout << "��  ��: " << GetName() << '\n';
		cout << "��  ��: " << GetBalance() << "��\n";
		cout << "������: " << GetBasicRate() << "%\n";
		if(creditRating == LEV_A) cout << "�ſ���: A(" << LEV_A << "%)\n";
		else if(creditRating == LEV_B) cout << "�ſ���: B(" << LEV_B << "%)\n";
		else if(creditRating == LEV_C) cout << "�ſ���: C(" << LEV_C << "%)\n";
	}
};