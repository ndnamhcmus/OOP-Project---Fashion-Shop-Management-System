#include "Person_Customer_Staff_Seller_Security.h"
#include <Tokenizer.h>
#include "Menu.h"
#include<string>

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
	cout << "Name - Date of Birth (DD/MM/YYYY) - Phone Number - Address (Form: Number-Street-Ward-District-City) - Base Salary\n";
	cout << "PLEASE ENTER THE INFORMATION AS FORM ABOVE\n";

	string line;
	do
	{
		getline(cin, line);
	} while (line == "");


	/// <summary>
	///			Fake test		///
	/// </summary>
	/*stringstream buffer;
	FakeVnTel tel;
	buffer << FakeName::next().FullName_to_string() << " - " << FakeBirthday::next().toString() << " - " << tel.toString() << " - "
		<< FakeHCMAddress::next().toString() << " - " << "5000000";
	line = buffer.str();*/


	if (line == "cancel")
	{
		throw exception("Cancel!!!");
	}


	
	auto Tok = Tokenizer::parse(line, " - ");
	if (Tok.size() != 5)
	{
		throw exception("Invalid, try again");
	}


	Tok.insert(Tok.begin() + 4, getNewID());
	Tok.push_back("0");
	Tok.push_back(Tok[5]);


	try
	{
		setStaffInfo(Tok);
	}
	catch (const std::exception&)
	{
		throw exception("Invalid, try again");
	}


	/*buffer.str("");
	buffer.clear();*/
}

string Staff::getStaffID()
{
	return _staff_id;
}

Staff* Staff::search(vector<Staff*> staffs, string for_who)
{
	string ID;
	cout << "Enter your Staff ID: ";
	while (ID == "")
	{
		getline(cin, ID);
	}
	if (ID == "cancel")
	{
		throw exception("Cancel!!!");
	}

	for (const auto& Staff : staffs)
	{
		if (Staff->getStaffID() == ID)
		{
			if (!(dynamic_cast<Seller*> (Staff)) && for_who != "Security")
			{
				throw StaffException("Not a Seller");
			}
			return Staff;
		}
	}

	throw exception("Not found");
}

void Staff::deleteStaff(vector<Staff*>& staffs)
{
	for (int i = 0; i < staffs.size(); i++)
	{
		if (this == staffs[i])
		{
			staffs.erase(staffs.begin() + i);
		}
	}
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
			try
			{
				staff->setStaffInfo(container[i]);
			}
			catch (const std::exception&)
			{
				throw exception("Something happened while Staff was setting up information");
			}
			staffs.push_back(staff);
		}
		else
		{
			Staff* staff = new Seller;
			try
			{
				staff->setStaffInfo(container[i]);
			}
			catch (const std::exception&)
			{
				throw exception("Something happened while Staff was setting up information");
			}
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
	int x = 100, y = 0;
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
			cout << mess.what() << endl;
			is_login = false;
			if (!(strcmp(mess.what(), "Cancel!!!")))
			{
				break;
			}
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

bool Staff::operator==(const Staff*& staff)
{
	if (this->_staff_id == staff->_staff_id)
	{
		return true;
	}
	return false;
}

void Staff::sort(vector <Staff*>& staffs, string sort_by)
{
	if (sort_by == "id")
	{
		for (int i = 0; i < staffs.size() - 1; i++)
		{
			for (int j = i + 1; j < staffs.size(); j++)
			{
				if (staffs[i]->getStaffID() > staffs[j]->getStaffID())
				{
					swap(staffs[i], staffs[j]);
				}
			}
		}

		return;
	}
	else if (sort_by == "sales")	///		fix		///
	{
		for (int i = 0; i < staffs.size() - 1; i++)
		{
			for (int j = i + 1; j < staffs.size(); j++)
			{
				if (dynamic_cast <Seller*> (staffs[i])->getSales() > dynamic_cast <Seller*> (staffs[j])->getSales())
				{
					swap(staffs[i], staffs[j]);
				}
			}
		}

		return;
	}
	else if (sort_by == "commission")
	{
		for (int i = 0; i < staffs.size() - 1; i++)
		{
			for (int j = i + 1; j < staffs.size(); j++)
			{
				if (dynamic_cast <Seller*> (staffs[i])->getCommission() > dynamic_cast <Seller*> (staffs[j])->getCommission())
				{
					swap(staffs[i], staffs[j]);
				}
			}
		}

		return;
	}
	else if (sort_by == "salary")
	{
		for (int i = 0; i < staffs.size() - 1; i++)
		{
			for (int j = i + 1; j < staffs.size(); j++)
			{
				if ((staffs[i])->getSalary() > staffs[j]->getSalary())
				{
					swap(staffs[i], staffs[j]);
				}
			}
		}

		return;
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
	if (tokens.size() != 3)
	{
		throw exception("Invalid, try again!!!");
	}

	_name = Tok[0];
	_date_of_birth = Date(stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]));
	_phone_number = Tok[2];


	tokens.clear();
	tokens = Tokenizer::parse(Tok[3], "-");

	if (tokens.size() != 5)
	{
		throw exception("Invalid, try again!!!");
	}
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
void Seller:: setSeller(string name, Date dob, string phone, Address add, string staff_id, double base_salary, double comission, int sales, double realsalary)
{
	Staff::setStaff(name, dob, phone, add, staff_id, base_salary);
	_commission = comission;
	_sales = sales;
	_real_salary = realsalary;
}

void Seller::setBaseSalary(double base_salary)
{
	_base_salary = base_salary;
}

void Seller::setCommission()
{
	if (_sales < 10)
	{
		_commission = 0;
	}
	else if (_sales >= 10 && _sales <20 )
	{
		_commission = double(_base_salary) / 10;
	}
	else
	{
		_commission = double(_base_salary) / 15;
	}

}

void Seller::updateSalary()
{
	setCommission();
	_real_salary = _base_salary + _commission;
}

void Seller::setSales(int sales)
{
	_sales = sales;
}

void Seller::setRealSalary(double real_salary)
{
	_real_salary = real_salary;
}

double Seller::getSalary()
{
	return _real_salary;
}

double Seller:: getCommission()
{
	setCommission();
	return _commission;
}
int Seller::getSales()
{
	return _sales;
}

void Seller::updateSales(const int& sales)
{
	_sales += sales;
}

void Seller::addSeller(vector<Staff*>& staff, Staff* sell)
{
	staff.push_back(sell);
}

string Seller::toString()
{
	string sell;
	sell += _name + " - " + _date_of_birth.toString() + " - " + _phone_number + " - " + _address.toString() + " - " + _staff_id + " - " + to_string(_base_salary) + " - " + to_string(_sales) +" - "+ to_string(_real_salary);
	return sell;
}

void Seller::setStaffInfo(vector<string> Tok)
{
	auto tokens = Tokenizer::parse(Tok[1], "/");
	if (tokens.size() != 3)
	{
		throw exception("Invalid, try again!!!");
	}


	_name = Tok[0];
	_date_of_birth = Date(stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]));
	_phone_number = Tok[2];


	tokens.clear();
	tokens = Tokenizer::parse(Tok[3], "-");
	if (tokens.size() != 5)
	{
		throw exception("Invalid, try again!!!");
	}


	_address = Address(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4]);
	_staff_id = Tok[4];
	_base_salary = stod(Tok[5]);
	_sales = stoi(Tok[6]);
	_real_salary = stod(Tok[7]);
}
void Seller::showStaffInfo()
{
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

void Seller::bestSellerOfMonth(vector <Staff*> staffs)
{
	vector <Seller> sellers;
	for (const auto& seller : staffs)
	{
		if (dynamic_cast <Seller*> (seller))
		{
			sellers.push_back(*(dynamic_cast <Seller*> (seller)));
		}
	}
	

	cout << "Name\t-\tDate of Birth\t-\tPhone Number\t-\tAddress\t-\tStaff ID\t-\tBase Salary\t-\tSales\t-\tSalary\n\n";
	Seller best = sellers[0];
	for (int i = 1; i < sellers.size(); i++)
	{
		if (sellers[i]._sales > best._sales)
			best = sellers[i];
	}
	for (int i = 0; i < sellers.size(); i++)
	{
		if (sellers[i]._sales == best._sales)
		{
			sellers[i].showStaffInfo();
			cout << endl << endl;
		}
	}

}