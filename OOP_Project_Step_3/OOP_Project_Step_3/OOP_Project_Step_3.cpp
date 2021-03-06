#include <iostream>
#include <string>

#define STR_LEN 100

using std::cout;
using std::cin;
using std::endl;

class Account {
private:
	int accID; // 중복검사를 하지 않는다.
	char* name;
	int balance; // 입금 및 출금액 검사를 하지 않는다.
public:
	Account(const int accID, const char* name, const int balance)
		: accID(accID), balance(balance)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	Account(const Account& account)
		: accID(account.accID), balance(account.balance)
	{
		name = new char[strlen(account.name) + 1];
		strcpy_s(name, strlen(account.name) + 1, account.name);
	}
	~Account()
	{
		delete[] name;
	}

	int GetAccID() { return accID; }
	char* GetName() { return name; }
	int GetBalance() { return balance; }

	void Deposit(int money) { balance += money; }
	void Withdraw(int money) { balance -= money; }

	void ShowAccountInfo()
	{
		cout << "계좌ID: " << accID << '\n';
		cout << "이 름: " << name << '\n';
		cout << "잔 액: " << balance << "원\n";
	}
};

enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOWINFO, EXIT };
Account* accountList[STR_LEN];
int accountNum;

int ShowMenu(); // 메뉴 출력
void CreateAccout(); // 계좌 생성
void Deposit(); // 입금
void Withdraw(); // 출금
void ShowAccountList(); // 계좌목록 출력

void customAccout(const int accID, const char* name, const int money)
{
	accountList[accountNum++] = new Account(accID, name, money);
}

int main()
{
	customAccout(111, "name1", 500);
	customAccout(112, "name2", 1000);
	customAccout(113, "name3", 5000);
	while(true) {
		switch(ShowMenu()) {
		case CREATE:
			CreateAccout();
			break;
		case DEPOSIT:
			Deposit();
			break;
		case WITHDRAW:
			Withdraw();
			break;
		case SHOWINFO:
			ShowAccountList();
			break;
		case EXIT:
			cout << "프로그램을 종료합니다.\n";
			return 0;
		default:
			break;
		}
		putchar('\n');
	}
	return 0;
}

int ShowMenu()
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

void CreateAccout()
{
	int accID = 0;
	char name[STR_LEN];
	int balance = 0;

	cout << "\n[계좌개설]\n";
	cout << "계좌ID: "; cin >> accID;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	accountList[accountNum++] = new Account(accID, name, balance);
}

void Deposit()
{
	int inputID = 0;
	int inputMoney = 0;
	int i;
	cout << "\n[입 금]\n";
	cout << "계좌ID: ";
	cin >> inputID;
	for(i = 0; i < accountNum; i++) {
		if(accountList[i]->GetAccID() == inputID) {
			break;
		}
	}
	if(i == accountNum) {
		cout << "올바른 계좌번호가 아닙니다.\n\n";
		cout << "저장된 계좌번호목록\n";
		for(int i = 0; i < accountNum; i++) {
			cout << "계좌ID: " << accountList[i]->GetAccID() << '\n';
		}
		return Deposit();
	}
	cout << "이 름: " << accountList[i]->GetName() << '\n';
	cout << "입금액: ";
	cin >> inputMoney;
	accountList[i]->Deposit(inputMoney);
	cout << "입금완료.";
}

void Withdraw()
{
	int inputID = 0;
	int inputMoney = 0;
	int i;
	cout << "\n[출 금]\n";
	cout << "계좌ID: ";
	cin >> inputID;
	for(i = 0; i < accountNum; i++) {
		if(accountList[i]->GetAccID() == inputID) {
			break;
		}
	}
	if(i == accountNum) {
		cout << "올바른 계좌번호가 아닙니다.\n";
		for(int i = 0; i < accountNum; i++) {
			cout << "계좌ID: " << accountList[i]->GetAccID() << '\n';
		}
		return Deposit();
	}
	cout << "이 름: " << accountList[i]->GetName() << '\n';
	cout << "출금액(현재 잔액: " << accountList[i]->GetBalance() << "원): ";
	cin >> inputMoney;
	if(accountList[i]->GetBalance() >= inputMoney) {
		accountList[i]->Withdraw(inputMoney);
	}
	else {
		cout << "잔액이 부족합니다.(현재 잔액: " << accountList[i]->GetBalance() << "원)\n";
		cout << "출금실패.\n";
		return;
	}
	cout << "출금완료.\n";
}

void ShowAccountList()
{
	cout << "\n[전체 계좌목록]\n";
	for(int i = 0; i < accountNum; i++) {
		cout << '\n';
		accountList[i]->ShowAccountInfo();
	}
}