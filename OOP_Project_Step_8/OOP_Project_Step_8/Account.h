#pragma once
class Account {
private:
	int accID; // 중복검사를 하지 않는다.
	char* name;
	int balance; // 입금 및 출금액 검사를 하지 않는다.
public:
	Account(int, const char*, int);
	Account(const Account&);
	~Account();
	int GetAccID() const;
	char* GetName() const;
	int GetBalance() const;
	virtual void Deposit(int);
	int Withdraw(int);
	virtual void ShowAccountInfo() const;
};
