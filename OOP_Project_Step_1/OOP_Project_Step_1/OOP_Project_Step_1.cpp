#include <iostream>
#include <cstring>

#define STR_LEN 100

using std::cout;
using std::cin;
using std::endl;

typedef struct {
	char name[STR_LEN];
	int accID; // 중복검사를 하지 않는다.
	int balance; // 입금 및 출금액 검사를 하지 않는다.
} Client;

Client accountList[STR_LEN];
int current_index;

int ShowMenu(); // 메뉴 출력
void CreateAccout(); // 계좌 생성
void Deposit(); // 입금
void Withdraw(); // 출금
void ShowAccountList(); // 계좌목록 출력


int main()
{
	int run = 1;
	while(run) {
		switch(ShowMenu()) {
		case 1:
			CreateAccout();
			break;
		case 2:
			Deposit();
			break;
		case 3:
			Withdraw();
			break;
		case 4:
			ShowAccountList();
			break;
		case 5:
			run = 0;
			break;
		default:
			break;
		}
		putchar('\n');
	}
	puts("프로그램을 종료합니다.");
    return 0;
}

int ShowMenu()
{
	int ch = 0;
	puts("-----Menu-----");
	puts("1. 계좌 개설");
	puts("2. 입 금");
	puts("3. 출 금");
	puts("4. 계좌정보 전체 출력");
	puts("5. 프로그램 종료");
	printf("선택>> ");
	scanf_s("%d", &ch);
	return ch;
}

void CreateAccout()
{
	puts("\n[계좌개설]");
	printf("계좌ID: ");
	scanf_s("%d", &accountList[current_index].accID);
	printf("이 름: ");
	scanf_s("%s", accountList[current_index].name, STR_LEN);
	printf("입금액: ");
	scanf_s("%d", &accountList[current_index].balance);

	current_index++;
}

void Deposit()
{
	int inputID = 0;
	int inputMoney = 0;
	int i;
	puts("\n[입 금]");
	printf("계좌ID: ");
	scanf_s("%d", &inputID);
	for(i = 0; i < current_index; i++) {
		if(accountList[i].accID == inputID) {
			break;
		}
	}
	if(i == current_index) {
		puts("올바른 계좌번호가 아닙니다.");
		ShowAccountList();
		return Deposit();
	}
	printf("이 름: %s\n", accountList[i].name);
	printf("입금액: ");
	scanf_s("%d", &inputMoney);
	accountList[i].balance += inputMoney;
	puts("입금완료.");
}

void Withdraw()
{
	int inputID = 0;
	int inputMoney = 0;
	int i;
	puts("\n[출 금]");
	printf("계좌ID: ");
	scanf_s("%d", &inputID);
	for(i = 0; i < current_index; i++) {
		if(accountList[i].accID == inputID) {
			break;
		}
	}
	if(i == current_index) {
		puts("올바른 계좌번호가 아닙니다.");
		ShowAccountList();
		return Deposit();
	}
	printf("이 름: %s\n", accountList[i].name);
	printf("출금액(현재 입금액: %d원): ", accountList[i].balance);
	scanf_s("%d", &inputMoney);
	if(accountList[i].balance >= inputMoney) {
		accountList[i].balance -= inputMoney;
	}
	else {
		printf("입금액이 부족합니다.(현재 입금액: %d원)\n", accountList[i].balance);
		puts("출금실패.");
		return;
	}
	puts("출금완료.");
}

void ShowAccountList()
{
	int i;
	puts("\n[전체 계좌목록]");
	for(i = 0; i < current_index; i++) {
		putchar('\n');
		printf("계좌ID: %d\n", accountList[i].accID);
		printf("이 름: %s\n", accountList[i].name);
		printf("잔 액: %d원\n", accountList[i].balance);
	}
}