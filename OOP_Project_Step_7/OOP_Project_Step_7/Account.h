#pragma once
class Account {
private:
	int accID; // �ߺ��˻縦 ���� �ʴ´�.
	char* name;
	int balance; // �Ա� �� ��ݾ� �˻縦 ���� �ʴ´�.
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
