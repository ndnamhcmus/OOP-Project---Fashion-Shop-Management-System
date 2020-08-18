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

	Person(string name, Date date_of_birth, string phone_number, Address address)
	{

	}



	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;
};

class Customer : public Person
{
private:

	string _customer_id;

public:

	Customer(string name, Date date_of_birth, string phone_number, Address address, string customer_id) : Person(name, date_of_birth, phone_number, address)
	{

	}



	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;
};

class Staff : public Person
{
protected:

	string _staff_id;
	double _base_salary = 0;

public:

	Staff(string name, Date date_of_birth, string phone_number, Address address, string staff_id, double _base_salary) : Person(name, date_of_birth, phone_number, address)
	{

	}




	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;
};

class Seller : public Staff
{
private:

	double _commission = 0;		// tiền hoa hồng
	static int _goods_sale;		// doanh số bán hàng

public:

	Seller(string name, Date date_of_birth, string phone_number, Address address, string staff_id, double _base_salary, double commission, int goods_sale) : Staff(name, date_of_birth, phone_number, address, staff_id, _base_salary)
	{

	}




	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;
};

class Security : public Staff
{
private:


public:

	Security(string name, Date date_of_birth, string phone_number, Address address, string staff_id, double _base_salary, double commission, int goods_sale) : Staff(name, date_of_birth, phone_number, address, staff_id, _base_salary)
	{

	}




	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;
};


#endif // !_PERSON_CUSTOMER_STAFF_SELLER_SECURITY_