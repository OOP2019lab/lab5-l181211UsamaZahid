#pragma once
#include <iostream>
#include <string>
using namespace std;

class bankAccount
{
	//Private variables
	int AccountNum;
	string AccountName;
	float balance;
	float balLimit;
	int*transactions;
	int nooftrans;
	int maxtrans;

public:
	//Constructor
	bankAccount(string username, int userid);

	//Setter for balance limit
	void setbalLimit(float limit);

	//Getters
	int getAccountNum()const;
	string getAccountName()const;
	int getBalance()const;
	int getnooftrans()const;
	int getmaxtrans()const;

	void printinfo()const;
	void withdraw(float amount);
	void deposit(float amount);
	
	//Destructor
	~bankAccount();

	//Utility function
	void incTranCapacity();
};