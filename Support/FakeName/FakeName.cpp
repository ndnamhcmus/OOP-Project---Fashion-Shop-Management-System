#include "FakeName.h"

//////////////////////////////////////////////////////////////////////////////////////////

////	Input random name into attributes		////
FullName::FullName()
{
	ifstream file;


	//	Random first name
	file.open("first_name.txt", ios::in);
	int random_number = 1 + rand() % (16 - 1 + 1);
	for (int i = 0; i < random_number; i++)
	{
		getline(file, this->_first_name);
	}
	file.close();


	//	Random middle name
	file.open("mid_name.txt", ios::in);
	random_number = 1 + rand() % (12 - 1 + 1);
	for (int i = 0; i < random_number; i++)
	{
		getline(file, this->_middle_name);
	}
	file.close();


	//	Random Last name
	file.open("last_name.txt", ios::in);
	random_number = 1 + rand() % (19 - 1 + 1);
	for (int i = 0; i < random_number; i++)
	{
		getline(file, this->_last_name);
	}
	file.close();
}

////		Get data function		////
string FullName::getFirstName()
{
	return this->_first_name;
}

string FullName::getMiddleName()
{
	return this->_middle_name;
}

string FullName::getLastName()
{
	return this->_last_name;
}

string FullName::FullName_to_string()
{
	stringstream writer;
	writer << _first_name << " " << _middle_name << " " << _last_name;
	return writer.str();
}

FullName::operator string()
{
	stringstream writer;
	writer << _first_name << " " << _middle_name << " " << _last_name;
	return writer.str();
}

//////////////////////////////////////////////////////////////////////////////////////////

FullName FakeName::next()
{
	FullName name;
	return name;
}


//ostream& operator<<(ostream& out, const FullName& name)
//{
//	out << name._first_name << " " << name._middle_name << " " << name._last_name;
//	return out;
//}