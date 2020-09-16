#ifndef _ACCOUNT_
#define _ACCOUNT_


#include <iostream>
#include <string>
#include <vector>
#include <exception>


#include "Bill.h"
#include "Person_Customer_Staff_Seller_Security.h"
#include "MembershipLevel.h"

using namespace std;

class Account
{
private:

	string _account_id;
	Customer _customer;
	vector <Bill> _bills;
	MembershipLevel _membership_level;

public:
	Account(string account_id = "", Customer customer = Customer() ,MembershipLevel membership_level = MembershipLevel());

	void sort(vector <Account> accounts, string sort_by);

	static Account search(vector <Account> accounts, string search_by);

	void setAccountInfo(vector<string>Tok);

	string findLastCustomer_ID_InFile();

	string findLastAccount_ID_InFile();

	void addAccountToFile(Account account);

	void deleteAccountInFile(string account_id);

	//void modifyAccountInFile(string account_id);

	vector <Bill> getBillListFromFile(string account_id);

	string getAccount_ID();

	string getMemberShipLevel();

	MembershipLevel getMemberShip();

	void setMemberShip(MembershipLevel membership);

	double getDiscount();

	static Account sign_in(vector <Account> accounts, string  account_id);
		
	Account sign_up(vector<Account>&);

	void showBillList();

	void showAccountInfo();

	static void saveAccountToFile(vector<Account>accounts);

	void deleteAccount(vector<Account>& acc, string account_id);

	//string modifyAccount();

	static void openAccountFile(vector <Account>& accounts, string path = "Account.csv");

	string toString();

public:

	bool operator!()
	{
		if (_account_id == "")
		{
			return true;
		}
		return false;
	}

public:

	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;
};


class AccountException : public exception
{
private:

	string _mess;

public:
	AccountException(string mess)
	{
		_mess = mess;
	}


	const char* what() const throw()
	{
		return _mess.c_str();
	}
};


#endif // !_ACCOUNT_