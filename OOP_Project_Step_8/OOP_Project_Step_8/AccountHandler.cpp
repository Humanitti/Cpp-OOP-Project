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
	cout << "1. 계좌 개설\n";
	cout << "2. 입 금\n";
	cout << "3. 출 금\n";
	cout << "4. 계좌정보 전체 출력\n";
	cout << "5. 프로그램 종료\n";
	cout << "선택>> ";
	cin >> ch;
	return ch;
}

void AccountHandler::CreateAccount()
{
	int ch = 0;
	cout << "\n[계좌종류선택]\n";
	cout << "1. 보통예금계좌\n";
	cout << "2. 신용신뢰계좌\n";
	cout << "선택>> "; cin >> ch;
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
	cout << "\n[보통예금계좌 개설]\n";
	do {
		cout << "계좌ID: "; cin >> accID;
	} while(CheckDuplAccID(accID));
	cout << "이  름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> basicRate;
	accountList[accountNum++] = new NormalAccount(accID, name, balance, basicRate);
}

void AccountHandler::CreateCreditAccount()
{
	int accID, balance, basicRate, level, creditRating = 0;
	char name[STR_LEN];
	cout << "\n[신용신뢰계좌 개설]\n";
	do {
		cout << "계좌ID: "; cin >> accID;
	} while(CheckDuplAccID(accID));
	cout << "이  름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> basicRate;
	do {
		cout << "신용등급(1toA, 2toB, 3toC): "; cin >> level;
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
			cout << "중복된 계좌ID가 존재합니다.\n";
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
	cout << "\n[입 금]\n";
	cout << "계좌ID: ";
	cin >> inputID;
	for(i = 0; i < accountNum; i++) {
		if(accountList[i]->GetAccID() == inputID) {
			cout << "이  름: " << accountList[i]->GetName() << '\n';
			cout << "입금액: "; cin >> inputMoney;
			accountList[i]->Deposit(inputMoney);
			cout << "입금완료.\n";
			return;
		}
	}
	cout << "올바른 계좌번호가 아닙니다.\n\n";
	cout << "저장된 계좌번호목록\n";
	for(int i = 0; i < accountNum; i++) {
		cout << "계좌ID: " << accountList[i]->GetAccID() << '\n';
	}
	return Deposit();
}

void AccountHandler::Withdraw()
{
	int inputID = 0;
	int inputMoney = 0;
	int i;
	cout << "\n[출 금]\n";
	cout << "계좌ID: ";
	cin >> inputID;
	for(i = 0; i < accountNum; i++) {
		if(accountList[i]->GetAccID() == inputID) {
			cout << "이  름: " << accountList[i]->GetName() << '\n';
			cout << "출금액(현재 잔액: " << accountList[i]->GetBalance() << "원): "; cin >> inputMoney;
			if(accountList[i]->Withdraw(inputMoney)) {
				cout << "출금완료.\n";
				return;
			}
			else {
				cout << "잔액이 부족합니다.(현재 잔액: " << accountList[i]->GetBalance() << "원)\n";
				return Withdraw();
			}
			return;
		}
	}
	cout << "올바른 계좌번호가 아닙니다.\n";
	for(int i = 0; i < accountNum; i++) {
		cout << "계좌ID: " << accountList[i]->GetAccID() << '\n';
	}
	return Deposit();
}

void AccountHandler::ShowAccountList() const
{
	cout << "\n---전체 계좌목록---\n";
	for(int i = 0; i < accountNum; i++) {
		cout << '\n';
		accountList[i]->ShowAccountInfo();
	}
}