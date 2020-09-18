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
	MembershipLevel _membership;
	Date _curr_date;
	vector<Product> _cart;

public:

	Bill()
	{

	}

	Bill(string id, string level, MembershipLevel membership, Date d, vector<Product> p);

private:

	void setBillInfo(vector<string>);

public:

	static void sort(vector <Bill> bills, string sort_by);

	static Bill search(vector <Bill> bills, string search_by);


	void showBillInfo();

public:

	static string getLastBillID(vector <Bill> bills);

	static string lastBill_ID_InFile();


	static int isFoundInList(vector <Bill>& bills, string ID);

	static void deleteBill(vector<Bill>& bills, Bill bill);

public:

	Bill getBill();

	string getID();

	Date getDate();

	string toString();

public:

	static void saveBillToFile(vector <Bill> bills);

	static void openBillFile(vector <Bill>& bills, string path = "Bill.csv");

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