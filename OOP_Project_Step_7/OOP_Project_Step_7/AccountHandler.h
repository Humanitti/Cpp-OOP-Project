#pragma once
#include "Account.h"
#define STR_LEN 100

class AccountHandler {
private:
	Account * accountList[STR_LEN];
	int accountNum;
public:
	AccountHandler();
	~AccountHandler();
	void customNormalAccount(const int, const char*, const int, const int);
	void customCreditAccount(const int, const char*, const int, const int, const int);
	int ShowMenu() const; // �޴� ���
	void CreateAccount(); // ���� ����
	void CreateNormalAccount(); // ���뿹�ݰ��� ����
	void CreateCreditAccount(); // �ſ�ŷڰ��� ����
	void Deposit(); // �Ա�
	void Withdraw(); // ���
	void ShowAccountList() const; // ���¸�� ���
};