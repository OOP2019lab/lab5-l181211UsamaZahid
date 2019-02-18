#include<iostream>
#include"Header.h"
using namespace std;
//Testing
int main()
{
	//Account Creation
	bankAccount myAccount("John Doe", 549002);

	//Checking withdrawal function
	myAccount.withdraw(2000);
	
	//Checking deposit function
	myAccount.deposit(250000);
	
	//Checking whether utility function increase trans pointer size works
	myAccount.deposit(50000);
	myAccount.deposit(6000);
	myAccount.withdraw(4000);
	myAccount.withdraw(5000);
	myAccount.withdraw(14000);
	myAccount.deposit(34000);
	myAccount.withdraw(4000);
	myAccount.withdraw(3000);
	myAccount.withdraw(4000);
	myAccount.withdraw(8000);
	myAccount.withdraw(4000);
	
	//Printing account info
	myAccount.printinfo();
	system("pause");
}