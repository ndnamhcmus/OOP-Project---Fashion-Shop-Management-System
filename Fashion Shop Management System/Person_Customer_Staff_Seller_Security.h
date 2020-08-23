#ifndef _PERSON_CUSTOMER_STAFF_SELLER_SECURITY_
#define _PERSON_CUSTOMER_STAFF_SELLER_SECURITY_



#include <iostream>
#include <string>
#include <vector>
#include <Date.h>
#include <FakeAddress.h>

using namespace std;


class Person
{
protected:

	string _name;
	Date _date_of_birth;
	string _phone_number;
	Address _address;

public:

	Person(string name = "", Date date= Date (0,0,0), string phone = "", Address add= Address("", "", "", "", ""))
	{

			_name = name;
			_date_of_birth = date;
			_phone_number = phone;
			_address = add;
	};
	void setName(string _name);
	void setDoB(Date dob);
	void setPhoneNumber(int phone);
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

	Customer(string name = "", Date date = Date(0, 0, 0), string phone = "", Address add = Address("", "", "", "", ""), string customer_id = "")
	{
		_customer_id = customer_id;
	};
	void setCustomerInfo(string name, Date dob, int phone, Address add, string customer_id);
	Customer getCustomerInfo();
	string toString();
	string getCustomerID();
	void showCustomerInfo();

	////		Friend		////

	friend class ExcelFstream;
	friend class ExcelIfstream;
	friend class ExcelOfstream;

};

/*
///////////////////////////// Do-ING /////////////////////
class Staff : public Person
{
protected:

	string _staff_id;
	double _base_salary = 0;

private:

	void setStaffID(string staff_id);
	void setBaseSalary(double salary);
	void setStaffInfo(string name, Date date, string phone, Address add, string staff_id, double base_salary);

public:

	Staff(string name = "", Date date = Date(0, 0, 0), string phone = "", Address add = Address("", "", "", "", ""), string staff_id = "", double base_salary = 0);
	string getStaffID();
	void showStaffInfo();
	void saveStaffInfoToFile();

	////  Friend //

	friend class ExcelFstream;
	friend class ExcelIfstream;
	friend class ExcelOfstream;
};



class Seller : public Staff
{
private:

	double _commission;		// tiền hoa hồng
	static int _goods_sale;		// doanh số bán hàng
	double _real_salary;

public:

	Seller(string name, Date date_of_birth, string phone_number, Address address, string staff_id, double _base_salary, double commission, int goods_sale, double real_salary) : Staff(name, date_of_birth, phone_number, address, staff_id, _base_salary)
	{
		_commission = commission;
		_goods_sale = goods_sale;
		_real_salary = real_salary;
	}


	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;
};



class Security : public Staff
{
private:


public:

	Security(string name, Date date_of_birth, string phone_number, Address address, string staff_id, double _base_salary) : Staff(name, date_of_birth, phone_number, address, staff_id, _base_salary)
	{

	}

	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;
};
*/

#endif // !_PERSON_CUSTOMER_STAFF_SELLER_SECURITY_