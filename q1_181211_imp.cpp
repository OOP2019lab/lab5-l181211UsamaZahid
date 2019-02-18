#include "q1_181211_header.h"
using namespace std;

//Constructor
bankAccount::bankAccount(string username , int userid)
{
	AccountNum = userid;
	AccountName = username;
	balance = 0;
	balLimit = 200000;
	nooftrans = 0;
	maxtrans = 10;
	transactions = new int[maxtrans];
}

//Setter for balance limit
void bankAccount::setbalLimit(float amount)
{
	if (amount > 0)
	{
		balLimit = amount;
		cout << "Balance limit has been changed\n";
	}
	else
		cout << "Balance limit change unsuccessful: Limit was -ve\n";
}

//Prints Account info
void bankAccount::printinfo()const
{
	cout << "-------------------------Account info--------------------\n";
	cout << "Account Name: " << AccountName;
	cout << "\nAccount Number: " << AccountNum;
	cout << "\nBalance: " << balance;
	cout << "\nTotal no of Transactions: " << nooftrans << endl;
	if (nooftrans > 0)
		cout << "Transactions:\n";
		for (int i = 0; i < nooftrans; i++)
		{
			cout << i+1 << ") " << transactions[i] << endl;
		}
}

//Withdraws money from account
void bankAccount::withdraw(float amount)
{
	if (amount > balance)
		cout << "Transaction Unsuccessful: Insufficient balance\n";
	else
	{
		cout << "Transaction Successful\n";
		nooftrans++;
		if (nooftrans > maxtrans)
			incTranCapacity();
		transactions[nooftrans - 1] = -amount;
		balance = balance - amount;
	}
}

//Deposits money in account
void bankAccount::deposit(float amount)
{
	if (amount + balance > balLimit)
		cout << "Transaction Unsuccessful: Above balance limit\n";
	else
	{
		cout << "Transaction Successful\n";
		nooftrans++;
		if (nooftrans > maxtrans)
			incTranCapacity();
		transactions[nooftrans - 1] = amount;
		balance = balance + amount;
	}
}

//Destructor
bankAccount::~bankAccount()
{
	delete[]transactions;
}

//Utility function to increase 'transaction' pointer size
void bankAccount::incTranCapacity()
{
	maxtrans = maxtrans * 2;
	int*newtrans;
	newtrans = new int[maxtrans];
	for (int i = 0; i < nooftrans; i++)
	{
		newtrans[i] = transactions[i];
	}
	delete[]transactions;
	transactions = newtrans;
}

//Getter functions
int bankAccount::getAccountNum()const
{
	return AccountNum;
}
string bankAccount::getAccountName()const
{
	return AccountName;
}
int bankAccount::getBalance()const
{
	return balance;
}
int bankAccount::getmaxtrans()const
{
	return maxtrans;
}
int bankAccount::getnooftrans()const
{
	return nooftrans;
}