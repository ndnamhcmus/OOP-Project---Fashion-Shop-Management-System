#include "Person_Customer_Staff_Seller_Security.h"

//int Seller::_goods_sale = 0;

////////      PERSON      ////////


void Person::setName(string name) { _name = name; }

void Person::setDoB(Date dob) { _date_of_birth = dob; }

void Person::setPhoneNumber(string phone) { _phone_number = phone; }

void Person::setAddress(Address add) { _address = add; }

string Person::getName() { return _name; };

Date Person::getDoB() { return _date_of_birth; }

string Person::getPhoneNumber() { return _phone_number; }

Address Person::getAddress() { return _address; }


////////////    CUSTOMER    /////////

void Customer::setCustomerID(string customer_id){ _customer_id = customer_id;}

void Customer:: setCustomerInfo(string name, Date dob, string phone, Address add,string customer_id)
{
	 Person::setName(name);
	 Person::setDoB(dob);
	 Person::setAddress(add);
	 Person::setPhoneNumber(phone);
	 setCustomerID(customer_id);
	
}

string Customer::getCustomerID() { return _customer_id; }

Customer Customer::getCustomerInfo()
{
	return Customer(getName(), getDoB(), getPhoneNumber(), getAddress(), getCustomerID());
}

string Customer:: toString()
{
	string cus;
	cus = _name;
	cus += "\t" +_customer_id + "\t"+  _date_of_birth.toString() + "\t"+_phone_number+ "\t"+_address.toString();
	return cus;
}

void Customer::showCustomerInfo()
{
	cout << "Customer Information : " << endl;
	cout << toString() << endl;
}

///////    STAFF /////////

void Staff::setStaffID(string staff_id) { _staff_id = staff_id; }

void Staff::setBaseSalary(double salary) { _base_salary = salary; }

void Staff::setStaffInfo(string name, Date dob, string phone, Address add, string staff_id, double base_salary)
{
	Person::setName(name);
	Person::setDoB(dob);
	Person::setAddress(add);
	Person::setPhoneNumber(phone);
	setStaffID(staff_id);
	setBaseSalary(base_salary);
}

string Staff::getStaffID()
{
	return _staff_id;
}

void Staff:: showStaffInfo()
{
	cout << _name << "\t" << _staff_id << "\t" << _date_of_birth.toString() + "\t" + _phone_number + "\t" + _address.toString() << endl;
}



///////// Security ////////

double Security::getSalary()
{
	return _base_salary;
}

void Security::setSecurityInfo(string name, Date dob, string phone, Address add, string staff_id, double base_salary)
{
	Staff::setStaffInfo(name, dob, phone, add, staff_id, base_salary);
}

void Security::saveStaffInfoToFile()
{
	//waiting
}
