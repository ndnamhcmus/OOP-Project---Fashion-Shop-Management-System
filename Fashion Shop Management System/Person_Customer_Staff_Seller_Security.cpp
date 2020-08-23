#include "Person_Customer_Staff_Seller_Security.h"

//int Seller::_goods_sale = 0;

////////      PERSON      ////////

//Person::Person(string name = "", Date date = Date(0, 0, 0), string phone = "", Address add = Address("", "", "", "", ""))


void Person::setName(string name) { _name = name; }

void Person::setDoB(Date dob) { _date_of_birth = dob; }

void Person::setPhoneNumber(int phone) { _phone_number = phone; }

void Person::setAddress(Address add) { _address = add; }

string Person::getName() { return _name; };

Date Person::getDoB() { return _date_of_birth; }

string Person::getPhoneNumber() { return _phone_number; }

Address Person::getAddress() { return _address; }


////////////    CUSTOMER    /////////

//Customer::Customer(string name = "", Date date = Date(0, 0, 0), string phone = "", Address add = Address("", "", "", "", ""), string customer_id = ""): Person(name , date,  phone ,  add )
	

void Customer:: setCustomerInfo(string name, Date dob, int phone, Address add,string customer_id)
{
	 Person::setName(name);
	 Person::setDoB(dob);
	 Person::setAddress(add);
	 Person::setPhoneNumber(phone);
	_customer_id = customer_id;
	
}

Customer Customer::getCustomerInfo()
{
	return Customer(getName(), getDoB(), getPhoneNumber(), getAddress(), getCustomerID());
}

string Customer:: toString()
{
	string cus;
	cus = _name;
	cus +="     "+ _date_of_birth.toString() + "     "+_phone_number+ "     "+_address.Address_to_string()+ "     "+_customer_id;
	return cus;
}

string Customer:: getCustomerID()
{
	return _customer_id;
}

void Customer::showCustomerInfo()
{
	cout << "Customer Information : " << endl;
	cout << toString() << endl;
}
/*
///////    STAFF /////////

Staff::Staff(string name = "", Date date = Date(0, 0, 0), string phone = "", Address add = Address("", "", "", "", ""), string staff_id = "", double base_salary = 0) :Person(name, date, phone, add)
{
	_staff_id = staff_id;
	_base_salary = base_salary;
}
*/