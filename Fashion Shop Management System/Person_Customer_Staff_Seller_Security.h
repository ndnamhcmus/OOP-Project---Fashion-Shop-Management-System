﻿#ifndef _PERSON_CUSTOMER_STAFF_SELLER_SECURITY_
#define _PERSON_CUSTOMER_STAFF_SELLER_SECURITY_



#include <iostream>
#include <string>
#include <vector>
#include <Date.h>
#include <FakeAddress.h>
#include <ExcelFstream.h>

using namespace std;


class Person
{
protected:

	string _name;
	Date _date_of_birth;
	string _phone_number;
	Address _address;

public:

	Person(string name = "", Date dob= Date (0,0,0), string phone = "", Address add= Address("", "", "", "", ""))
	{

			_name = name;
			_date_of_birth = dob;
			_phone_number = phone;
			_address = add;
	};
	void setName(string _name);
	void setDoB(Date dob);
	void setPhoneNumber(string phone);
	void setAddress(Address add);

	string getName();
	Date getDoB();
	string getPhoneNumber();
	Address getAddress();

	////////     Friend    //////////

	friend class ExcelFstream;
	friend class ExcelIfstream;
	friend class ExcelOfstream;
};





class Customer : public Person
{
private:

	string _customer_id;

public:

	Customer(string name = "", Date dob = Date(0, 0, 0), string phone = "", Address add = Address("", "", "", "", ""), string customer_id = ""): Person(name, dob, phone, add)

	{
		_customer_id = customer_id;
	};
	void setCustomerID(string customer_id);
	void setCustomerInfo(string name, Date dob, string phone, Address add, string customer_id);

	string getCustomerID();
	Customer getCustomerInfo();

	string toString();
	void showCustomerInfo();
	void parse(string line);
	

	////		Friend		////

	friend class ExcelFstream;
	friend class ExcelIfstream;
	friend class ExcelOfstream;

};





class Staff : public Person
{
protected:

	string _staff_id;
	double _base_salary = 0;

	void setStaff(string name, Date dob, string phone, Address add, string staff_id, double base_salary);
	void setStaffID(string staff_id);
	void setBaseSalary(double salary);
	
public:

	Staff(string name = "", Date dob = Date(0, 0, 0), string phone = "", Address add = Address("", "", "", "", ""), string staff_id = "", double base_salary = 0) : Person(name, dob, phone, add)
	{
		_staff_id = staff_id;
		_base_salary = base_salary;
	}

	void virtual setStaffInfo(vector<string> Tok) {};
	string getStaffID();
	Staff* search(vector<Staff*>staffs, string searchID);
	void showBaseStaffInfo();

	string virtual toString() { return 0; };
	void saveStaffInfoToFile(vector<Staff*> staffs);
	void openStaffToRead(vector <Staff*>& staffs);

	////  Friend //

	friend class ExcelFstream;
	friend class ExcelIfstream;
	friend class ExcelOfstream;
};






class Security : public Staff
{

public:

	Security(string name = "", Date dob = Date(0, 0, 0), string phone = "", Address add = Address("", "", "", "", ""), string staff_id = "", double base_salary = 0) : Staff(name, dob, phone, add, staff_id, base_salary) {};

	void setSecurity(string name, Date dob, string phone, Address add, string staff_id, double base_salary);
	void setStaffInfo(vector<string> Tok);
	double getSalary();

	void addSecurity(vector<Staff*>& staff, Staff* secu);
	
	string toString();
	void showSecurityInfo();
	void parse(string line);

	/// Friend ///

	friend class ExcelFstream;
	friend class ExcelIfstream;
	friend class ExcelOfstream;
};






class Seller : public Staff
{
private:

	double _commission;		// tiền hoa hồng
	int _goods_sale;		// doanh số bán hàng
	double _real_salary;

public:

	Seller(string name = "", Date dob = Date(0, 0, 0), string phone = "", Address add = Address("", "", "", "", ""), string staff_id = "", double base_salary = 0,double commission=0, int goods_sale =0,double real_salary=0) : Staff(name, dob, phone, add, staff_id, base_salary)
	{
		_commission = commission;
		_goods_sale = goods_sale;
		_real_salary = real_salary;
	}

	void setSeller(string name, Date dob, string phone, Address add, string staff_id, double base_salary, double comission, int goodsale, double realsalary);
	void setCommission();
	void setGoodsSale(int goodsale);
	void setRealSalary();
	void setStaffInfo(vector<string> Tok);
	double getSalary();
	double getCommission();

	void addSeller(vector<Staff*>& staff, Staff* sell);

	string toString();
	void showSellerInfo();
	void parse(string line);


	//// FRIEND ////

	friend class ExcelFstream;
	friend class ExcelIfstream;
	friend class ExcelOfstream;
};



#endif // !_PERSON_CUSTOMER_STAFF_SELLER_SECURITY_