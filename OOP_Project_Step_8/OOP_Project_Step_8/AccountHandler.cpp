#include "AccountHandler.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler(): accountNum(0) {}
AccountHandler::~AccountHandler()
{
	for(int i = 0; i < accountNum; i++) {
		delete accountList[i];
	}
}

void AccountHandler::customNormalAccount(int accID, const char* name, int money, int basicRate)
{
	accountList[accountNum++] = new NormalAccount(accID, name, money, basicRate);
}

void AccountHandler::customCreditAccount(int accID, const char* name, int money, int basicRate, int creditRating)
{
	accountList[accountNum++] = new HighCreditAccount(accID, name, money, basicRate, creditRating);
}

int AccountHandler::ShowMenu() const
{
	int ch = 0;
	cout << "-----Menu-----\n";
	cout << "1. ���� ����\n";
	cout << "2. �� ��\n";
	cout << "3. �� ��\n";
	cout << "4. �������� ��ü ���\n";
	cout << "5. ���α׷� ����\n";
	cout << "����>> ";
	cin >> ch;
	return ch;
}

void AccountHandler::CreateAccount()
{
	int ch = 0;
	cout << "\n[������������]\n";
	cout << "1. ���뿹�ݰ���\n";
	cout << "2. �ſ�ŷڰ���\n";
	cout << "����>> "; cin >> ch;
	if(ch == NORMAL) {
		CreateNormalAccount();
	}
	else if(ch == CREDIT) {
		CreateCreditAccount();
	}
	else {
		return CreateAccount();
	}
}

void AccountHandler::CreateNormalAccount()
{
	int accID, balance, basicRate;
	char name[STR_LEN];
	cout << "\n[���뿹�ݰ��� ����]\n";
	do {
		cout << "����ID: "; cin >> accID;
	} while(CheckDuplAccID(accID));
	cout << "��  ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> basicRate;
	accountList[accountNum++] = new NormalAccount(accID, name, balance, basicRate);
}

void AccountHandler::CreateCreditAccount()
{
	int accID, balance, basicRate, level, creditRating = 0;
	char name[STR_LEN];
	cout << "\n[�ſ�ŷڰ��� ����]\n";
	do {
		cout << "����ID: "; cin >> accID;
	} while(CheckDuplAccID(accID));
	cout << "��  ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> basicRate;
	do {
		cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> level;
		if(level == 1) creditRating = LEV_A;
		else if(level == 2) creditRating = LEV_B;
		else if(level == 3) creditRating = LEV_C;
	} while(creditRating == 0);
	accountList[accountNum++] = new HighCreditAccount(accID, name, balance, basicRate, creditRating);
}

bool AccountHandler::CheckDuplAccID(const int accID)
{
	for(int i = 0; i < accountNum; i++) {
		if(accountList[i]->GetAccID() == accID) {
			cout << "�ߺ��� ����ID�� �����մϴ�.\n";
			return true;
		}
	}
	return false;
}

void AccountHandler::Deposit()
{
	int inputID = 0;
	int inputMoney = 0;
	int i;
	cout << "\n[�� ��]\n";
	cout << "����ID: ";
	cin >> inputID;
	for(i = 0; i < accountNum; i++) {
		if(accountList[i]->GetAccID() == inputID) {
			cout << "��  ��: " << accountList[i]->GetName() << '\n';
			cout << "�Աݾ�: "; cin >> inputMoney;
			accountList[i]->Deposit(inputMoney);
			cout << "�ԱݿϷ�.\n";
			return;
		}
	}
	cout << "�ùٸ� ���¹�ȣ�� �ƴմϴ�.\n\n";
	cout << "����� ���¹�ȣ���\n";
	for(int i = 0; i < accountNum; i++) {
		cout << "����ID: " << accountList[i]->GetAccID() << '\n';
	}
	return Deposit();
}

void AccountHandler::Withdraw()
{
	int inputID = 0;
	int inputMoney = 0;
	int i;
	cout << "\n[�� ��]\n";
	cout << "����ID: ";
	cin >> inputID;
	for(i = 0; i < accountNum; i++) {
		if(accountList[i]->GetAccID() == inputID) {
			cout << "��  ��: " << accountList[i]->GetName() << '\n';
			cout << "��ݾ�(���� �ܾ�: " << accountList[i]->GetBalance() << "��): "; cin >> inputMoney;
			if(accountList[i]->Withdraw(inputMoney)) {
				cout << "��ݿϷ�.\n";
				return;
			}
			else {
				cout << "�ܾ��� �����մϴ�.(���� �ܾ�: " << accountList[i]->GetBalance() << "��)\n";
				return Withdraw();
			}
			return;
		}
	}
	cout << "�ùٸ� ���¹�ȣ�� �ƴմϴ�.\n";
	for(int i = 0; i < accountNum; i++) {
		cout << "����ID: " << accountList[i]->GetAccID() << '\n';
	}
	return Deposit();
}

void AccountHandler::ShowAccountList() const
{
	cout << "\n---��ü ���¸��---\n";
	for(int i = 0; i < accountNum; i++) {
		cout << '\n';
		accountList[i]->ShowAccountInfo();
	}
}