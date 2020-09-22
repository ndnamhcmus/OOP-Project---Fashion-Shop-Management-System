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

private:

	void setAccountInfo(vector<string>Tok);

	string getLastCustomerID(vector <Account> accounts);

	string getLastAccountID(vector <Account> accounts);

public:

	void addBill(Bill bill);

public:

	static void sort(vector <Account> accounts, string sort_by);

	static Account search(vector <Account> accounts, string search_by);

	void deleteAccount(vector<Account>& acc, string account_id);


public:


	string getID();

	string getMembershipLevel();

	MembershipLevel getMemberShip();

	double getDiscount();


public:

	void setMemberShip(MembershipLevel membership);

public:

	static Account sign_in(vector <Account> accounts, string  account_id);
		
	Account sign_up(vector<Account>&);

public:

	void showBillList();

	void showAccountInfo();



public:

	static void openAccountList(vector <Account>& accounts, string directory = "../Fashion Shop Management System/Database/Account.csv");

	static void saveAccountList(vector<Account>accounts, string directory = "../Fashion Shop Management System/Database/Account.csv");

private:

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

private:	///		Các chức năng không dùng đến nên bỏ vào private		///

	void addAccountToFile(Account account);

	void deleteAccountInFile(string account_id);

	vector <Bill> getBillListFromFile(string account_id);

	string modifyAccount()
	{

	}
	void modifyAccountInFile(string account_id)
	{

	}

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