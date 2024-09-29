#include <iostream>
#include <Windows.h>
using namespace std;


class ATM
{
private:
	float total;

public:
	ATM();
	void deposit(float userInput);
	void withdraw(float userInput);
	float checkBalance();
	int exit();
	void fullyWorking(int menu, float userInput);
	enum MenuOptions
	{Deposit = 1, Withdraw, CheckBalance, Exit};
};

ATM::ATM() 
{
	total = 0.f;
}

void ATM::fullyWorking(int menu, float userInput)
{
	while (menu != 4) 
	{
		cout << "Enter 1 if you would like to deposit. \nEnter 2 if you would like to withdraw. \nEnter 3 if you would like to check your balance. \nEnter 4 to exit the menu.\n";
		cin >> menu;
		switch (menu)
		{
		case Deposit:
			cout << "Enter the amount you would like to deposit.\n";
			cin >> userInput;
			if (userInput > 0) {
				deposit(userInput);
				cout << "You have succesfully deposited" << ' ' << '$' << userInput << endl;
			}
			else { cout << "You can't deposit a negative number\n"; }
			break;
		case Withdraw:
			cout << "Enter the amount you would like to withdraw.\n";
			cin >> userInput;
			withdraw(userInput);
			if (userInput <= total) cout << "You have succesfully withdrawn" << ' ' << '$' << userInput << endl;
			break;
		case CheckBalance:
			cout << "Your balance is:" << ' ' << '$' << checkBalance() << endl;
			break;
		case Exit:
			cout << "Thank you for using AhmadsATM." << endl;
			exit();
			break;
		}
		Sleep(1000);
		system("cls");
	}
}

int ATM::exit()
{
	return 0;
}

float ATM::checkBalance()
{
	return this->total;
}

void ATM::withdraw(float userInput)
{
	if (userInput <= total)
		this->total -= userInput;
	else if (userInput > total ) 
		cout << "You have insufficient funds." << endl;
}


void ATM::deposit(float userInput) 
{
	this->total += userInput;
}


int main()
{
	int menu = -10;
	float userInput = 0.f;
	ATM atm; 
	atm.fullyWorking(menu,userInput);

	return 0;
};

