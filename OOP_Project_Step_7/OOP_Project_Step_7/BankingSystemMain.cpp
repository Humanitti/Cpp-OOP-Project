#include "BankingCommonDecl.h"

int main()
{
	AccountHandler manager;
	manager.customNormalAccount(111, "name1", 500, 2);
	manager.customNormalAccount(112, "name2", 1000, 5);
	manager.customCreditAccount(113, "name3", 5000, 5, LEV_B);
	while(true) {
		switch(manager.ShowMenu()) {
		case CREATE:
			manager.CreateAccount();
			break;
		case DEPOSIT:
			manager.Deposit();
			break;
		case WITHDRAW:
			manager.Withdraw();
			break;
		case SHOWINFO:
			manager.ShowAccountList();
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