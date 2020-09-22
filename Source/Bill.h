#ifndef _BILL_
#define _BILL_


#include <iostream>
#include <string>
#include <Date.h>
#include <Time.h>


#include "Product.h"
#include "MembershipLevel.h"


class Bill
{
private:

	string _bill_id;
	string _level;
	string _account_id;

	MembershipLevel _membership;

	Date _curr_date;

	vector<Product> _cart;

public:

	Bill()
	{

	}

	Bill(string id, string level, MembershipLevel membership, Date d, vector<Product> p, string account_id);

private:

	void setBillInfo(vector<string>);

public:

	static void sort(vector <Bill> bills, string sort_by);

	Bill search(vector <Bill> bills, string search_by);

	void showBillInfo();

public:

	static string getLastBillID(vector <Bill> bills);

	static string lastBill_ID_InFile();

	static int isFoundInList(vector <Bill>& bills, string ID);

	void deleteBill(vector<Bill>& bills);

public:

	void setMembershipLevel(string level);

public:

	Bill getBill();

	string getID();

	string getAccountID();

	Date getDate();

	string toString();

public:

	static void saveBillList(vector <Bill> bills, string directory = "../Fashion Shop Management System/Database/Bill.csv");

	static void openBillList(vector <Bill>& bills, string directory = "../Fashion Shop Management System/Database/Bill.csv");

public:

	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;
};


class BillException : public exception
{
private:

	string _mess;

public:
	BillException(const string& mess)
	{
		_mess = mess;
	}

	const char* what() const throw()
	{
		return _mess.c_str();
	}

};

#endif // !_BILL_
