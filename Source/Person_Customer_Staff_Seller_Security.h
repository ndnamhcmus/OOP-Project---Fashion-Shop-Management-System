#ifndef _PERSON_CUSTOMER_STAFF_SELLER_SECURITY_
#define _PERSON_CUSTOMER_STAFF_SELLER_SECURITY_



#include <iostream>
#include <string>
#include <vector>
#include <exception>


#include <Date.h>
#include <ExcelFstream.h>
#include <Tokenizer.h>
#include <FakeAddress.h>
#include <FakeAddress.h>
#include <FakeName.h>
#include <FakeBirthday.h>
#include <FakeVnTel.h>

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

public:

	virtual void setNewStaff();

	string getStaffID();
	void setLastID(vector <Staff*> staffs);

	virtual void setStaffInfo(vector<string> Tok) = 0;
	virtual double getSalary() = 0;
	virtual void showStaffInfo() = 0;
	virtual string toString() = 0;

	static void saveStaffList(vector<Staff*> staffs, string directory = "../Fashion Shop Management System/Database/Staff.csv");
	static void openStaffList(vector <Staff*>& staffs, string directory = "../Fashion Shop Management System/Database/Staff.csv");

	static bool login(vector <Staff*> staffs);
	static void sort(vector <Staff*>& staffs, string sort_by);
	static Staff* search(vector<Staff*>staffs, string for_what = "Seller");
	void deleteStaff(vector <Staff*>& staffs);


private:

	string last_ID;
	string getNewID();

public:

	bool operator==(const Staff*& staff);

public:


	////  Friend //

	friend class ExcelFstream;
	friend class ExcelIfstream;
	friend class ExcelOfstream;
};






class Security : public Staff
{

public:

	Security(string name = "", Date dob = Date(0, 0, 0), string phone = "", Address add = Address("", "", "", "", ""), string staff_id = "", double base_salary = 0) : Staff(name, dob, phone, add, staff_id, base_salary) {};

public:

	void setNewStaff();

	void setSecurity(string name, Date dob, string phone, Address add, string staff_id, double base_salary);
	void setStaffInfo(vector<string> Tok);
	double getSalary();

	void addSecurity(vector<Staff*>& staff, Staff* secu);
	
	string toString();
	void showStaffInfo();
	void parse(string line);

	/// Friend ///

	friend class ExcelFstream;
	friend class ExcelIfstream;
	friend class ExcelOfstream;
};






class Seller : public Staff
{
private:

	double _real_salary;
	double _commission;		// tiền hoa hồng
	int _sales;		// doanh số bán hàng

public:

	Seller(string name = "", Date dob = Date(0, 0, 0), string phone = "", Address add = Address("", "", "", "", ""), string staff_id = "", double base_salary = 0,double commission=0, int goods_sale =0,double real_salary=0) : Staff(name, dob, phone, add, staff_id, base_salary)
	{
		_commission = commission;
		_sales = goods_sale;
		_real_salary = real_salary;
	}

private:

	void parse(string line);

	string toString();

private:

	void setCommission();

public:

	void setNewStaff();

	void setSeller(string name, Date dob, string phone, Address add, string staff_id, double base_salary, double comission, int goodsale, double realsalary);
	void setBaseSalary(double base_salary);
	void setSales(int sales = 0);
	void setRealSalary(double real_salary);
	void setStaffInfo(vector<string> Tok);

	double getSalary();
	double getCommission();
	int getSales();

	void updateSales(const int& sales);
	void updateSalary();


public:

	void addSeller(vector<Staff*>& staff, Staff* sell);

	void showStaffInfo();

	static void bestSellerOfMonth(vector <Staff*> staffs);


	//// FRIEND ////

	friend class ExcelFstream;
	friend class ExcelIfstream;
	friend class ExcelOfstream;
};

class StaffException : public exception
{
private:

	string _mess;

public:

	StaffException(string mess)
	{
		_mess = mess;
	}

public:

	const char* what() const throw()
	{
		return _mess.c_str();
	}

};

#endif // !_PERSON_CUSTOMER_STAFF_SELLER_SECURITY_