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
	int ShowMenu() const; // 메뉴 출력
	void CreateAccount(); // 계좌 생성
	void CreateNormalAccount(); // 보통예금계좌 생성
	void CreateCreditAccount(); // 신용신뢰계좌 생성
	void Deposit(); // 입금
	void Withdraw(); // 출금
	void ShowAccountList() const; // 계좌목록 출력
};