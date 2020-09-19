#include "Person_Customer_Staff_Seller_Security.h"
#include <Tokenizer.h>
#include "Menu.h"
#include<string>
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
	cus += " - " +_customer_id + " - "+  _date_of_birth.toString() + " - "+_phone_number+ " - "+_address.toString();
	return cus;
}

void Customer::showCustomerInfo()
{
	cout << "Customer Information : " << endl;
	cout << toString() << endl;
}

void Customer::parse(string line)
{
	auto Tok = Tokenizer::parse(line, " - ");
	this->_name = Tok[0];
	this->_customer_id = Tok[1];
	this->_date_of_birth.toString() = Tok[2];
	this->_phone_number = Tok[3];
	this->_address = Tok[4];
}




///////    STAFF /////////

void Staff::setStaffID(string staff_id) { _staff_id = staff_id; }

void Staff::setBaseSalary(double salary) { _base_salary = salary; }

void Staff::setStaff(string name, Date dob, string phone, Address add, string staff_id, double base_salary)
{
	Person::setName(name);
	Person::setDoB(dob);
	Person::setAddress(add);
	Person::setPhoneNumber(phone);
	setStaffID(staff_id);
	setBaseSalary(base_salary);
}

void Staff::setNewStaff()
{
	cout << "Name - DD/MM/YYYY(Date of Birth) - Phone Number - Address - Base Salary\n";
	cout << "PLEASE ENTER THE INFORMATION IN THE FORM ABOVE\n";
	string line;
	getline(cin, line);
	if (line == "cancel")
	{
		throw StaffException(line);
	}


	auto Tok = Tokenizer::parse(line, " - ");
	Tok.insert(Tok.begin() + 4, getNewID());
	Tok.push_back("0");
	Tok.push_back(Tok[5]);


	setStaffInfo(Tok);
}

string Staff::getStaffID()
{
	return _staff_id;
}

Staff* Staff::search(vector<Staff*> staffs)
{
	string ID;
	cout << "Enter your Staff ID: ";
	getline(cin, ID);
	if (ID == "cancel")
	{
		throw exception("Cancel!!!");
	}

	for (const auto& Staff : staffs)
	{
		if (Staff->getStaffID() == ID)
		{
			if (!(dynamic_cast<Seller*> (Staff)))
			{
				throw StaffException("Not a Seller");
			}
			return Staff;
		}
	}

	throw exception("Not found");
}

void Staff::saveStaffList(vector<Staff*> staffs, string directory)
{
	string buffer;
	ExcelFstream file;
	file.open(directory, ios::out);


	for (int i = 0; i < staffs.size(); i++)
	{
		buffer = staffs[i]->toString();
		file.writeExcelString(buffer);
	}
	file.close();
}

void Staff::openStaffList(vector <Staff*>& staffs, string directory)
{
	ExcelFstream file;
	file.open(directory, ios::in | ios::app);

	vector <vector <string>> container;
	file.readExcelString(container);
	
	for (int i = 0; i < container.size(); i++)
	{
		if (container[i].size() == 6)
		{
			Staff* staff= new Security;
			staff->setStaffInfo(container[i]);
			staffs.push_back(staff);
		}
		else
		{
			Staff* staff = new Seller;
			staff->setStaffInfo(container[i]);
			staffs.push_back(staff);
		}
	}
	file.close();


	if (!(staffs.size()))
	{
		throw exception("Staff list is empty");
	}
}

bool Staff::login(vector <Staff*> staffs)
{
	int x = 55, y = 0;
	bool is_login = false;
	stringstream buffer;
	do
	{
		system("cls");


		buffer.str("");
		buffer.clear();


		buffer << "LOGIN";
		Menu::gotoxy(x - buffer.str().size() / 2, y);
		cout << buffer.str() << endl;
		
		try
		{
			if (Staff::search(staffs))
			{
				is_login = true;
			}
		}
		catch (const exception& mess)
		{
			if (!(strcmp(mess.what(), "Cancel!!!")))
			{
				break;
			}


			cout << mess.what() << endl;
			is_login = false;
		}
		system("pause");
	} while (!(is_login));
	return is_login;
}


void Staff::setLastID(vector<Staff*> staffs)
{
	last_ID = staffs[staffs.size() - 1]->getStaffID();
}

string Staff::getNewID()
{
	return to_string(stoi(last_ID) + 1);
}

void Staff:: sort(vector <Staff*>& staffs)
{
	for (int i = 0; i < staffs.size()-1; i++)
	{
		if (staffs[i]->_staff_id > staffs[i + 1]->_staff_id)
		{
			Staff* a = staffs[i];
			staffs[i] = staffs[i + 1];
			staffs[i + 1] = a;
		}
	}
}



///////// Security ////////

void Security::setNewStaff()
{
	Staff::setNewStaff();
}

void Security::setSecurity(string name, Date dob, string phone, Address add, string staff_id, double base_salary)
{
	Staff::setStaff(name, dob, phone, add, staff_id, base_salary);
}

void Security::setStaffInfo(vector<string> Tok)
{
	auto tokens = Tokenizer::parse(Tok[1], "/");


	_name = Tok[0];
	_date_of_birth = Date(stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]));
	_phone_number = Tok[2];


	tokens.clear();
	tokens = Tokenizer::parse(Tok[3], "-");


	_address = Address(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4]);
	_staff_id = Tok[4];
	_base_salary = stod(Tok[5]);
}

double Security::getSalary()
{
	return _base_salary;
}

void Security::addSecurity(vector<Staff*>& staff, Staff* secu)
{
	staff.push_back(secu);
}

string Security::toString()
{
	string secu;
	secu += _name + " - " + _date_of_birth.toString() + " - " + _phone_number + " - " + _address.toString() + " - " + _staff_id + " - " + to_string(_base_salary);
	return secu;
}

void Security::parse(string line)
{
	auto Tok = Tokenizer::parse(line, " - ");
	this->setStaffInfo(Tok);
}

void Security::showStaffInfo()
{
	cout << toString();
}





///////////////////// SELLER ///////////
void Seller:: setSeller(string name, Date dob, string phone, Address add, string staff_id, double base_salary, double comission, int goodsale, double realsalary)
{
	Staff::setStaff(name, dob, phone, add, staff_id, base_salary);
	_commission = comission;
	_goods_sale = goodsale;
	_real_salary = realsalary;
}

void Seller:: setCommission()
{
	if (_goods_sale < 10)
	{
		_commission = 0;
	}
	else if (_goods_sale >= 10 && _goods_sale <20 )
	{
		_commission = _base_salary / 10;
	}
	else
	{
		_commission = _base_salary / 15;
	}

}

void Seller::setGoodsSale(int goodsale)
{
	_goods_sale = goodsale;
}

void Seller:: setRealSalary()
{
	_real_salary = _base_salary + _commission;
}

double Seller::getSalary()
{
	return _real_salary;
}

double Seller:: getCommission()
{
	return _commission;
}
void Seller::addSeller(vector<Staff*>& staff, Staff* sell)
{
	staff.push_back(sell);
}

string Seller::toString()
{
	string sell;
	sell += _name + " - " + _date_of_birth.toString() + " - " + _phone_number + " - " + _address.toString() + " - " + _staff_id + " - " + to_string(_base_salary) + " - " + to_string(_goods_sale) +" - "+ to_string(_real_salary);
	return sell;
}

void Seller::setStaffInfo(vector<string> Tok)
{
	auto tokens = Tokenizer::parse(Tok[1], "/");


	_name = Tok[0];
	_date_of_birth = Date(stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]));
	_phone_number = Tok[2];


	tokens.clear();
	tokens = Tokenizer::parse(Tok[3], "-");


	_address = Address(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4]);
	_staff_id = Tok[4];
	_base_salary = stod(Tok[5]);
	_goods_sale = stoi(Tok[6]);
	_real_salary = stod(Tok[7]);
}
void Seller::showStaffInfo()
{
	/*Staff::showStaffInfo();
	cout << " - " << _goods_sale << " - " << _real_salary;*/
	cout << toString();
}

void Seller::parse(string line)
{
	auto Tok = Tokenizer::parse(line, " - ");
	this->setStaffInfo(Tok);
}

void Seller::setNewStaff()
{
	Staff::setNewStaff();
}

void Seller:: bestSellerOfMonth()
{
	ExcelFstream file;
	file.open("Staff.csv", ios::in | ios::app);

	vector <vector <string>> container;
	file.readExcelString(container);

	vector<Seller> seller;
	for (int i = 0; i < container.size(); i++)
	{
		if (container[i].size() == 9)
		{
			Seller sel;
			sel.setStaffInfo(container[i]);
			seller.push_back(sel);
		}
	}

	Seller best= seller[0];
	for (int i = 0; i < seller.size(); i++)
	{
		if (seller[i]._goods_sale > best._goods_sale)
			best = seller[i];
	}
	cout << "BEST SELLER OF MONTH" << endl;
	best.showStaffInfo();
	for (int i = 0; i < seller.size(); i++)
	{
		if (seller[i]._goods_sale == best._goods_sale)
			seller[i].showStaffInfo();
	}

}