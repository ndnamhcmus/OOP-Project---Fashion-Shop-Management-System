#ifndef _ACCOUNT_
#define _ACCOUNT_


#include <iostream>
#include <string>
#include <vector>
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

	Account search(vector <Account> accounts, string search_by);

	void setAccountInfo(vector<string>Tok);

	string findLastAccount_ID_InFile();

	void addAccountToFile(Account account);

	void deleteAccountInFile(string account_id);

	//void modifyAccountInFile(string account_id);

	vector <Bill> getBillListFromFile(string account_id);

	string getAccount_ID();

	string getMemberShipLevel();

	double getDiscount();

	void sign_in(string  account_id);
		
	void sign_up(vector<Account>&);

	void showBillList();

	void showAccountInfo();

	static void saveAccountToFile(vector<Account>accounts);

	void deleteAccount(vector<Account>& acc, string account_id);

	//string modifyAccount();

	static void openAccountFile(vector <Account>& accounts, string path = "Account.csv");

	string toString();

	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;
};


#endif // !_ACCOUNT_