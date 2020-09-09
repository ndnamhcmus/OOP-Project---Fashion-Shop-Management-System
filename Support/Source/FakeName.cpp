#include "FakeName.h"

//////////////////////////////////////////////////////////////////////////////////////////

void FullName::generateRandomName(string& first_name, string& middle_name, string& last_name)
{
	Random rng;
	first_name = _first_name_list[rng.next(0, 15)];
	middle_name = _middle_name_list[rng.next(0, 11)];
	last_name = _last_name_list[rng.next(0, 18)];
}

////	Input random name into attributes		////
FullName::FullName(string first_name, string middle_name, string last_name)
{
	if (first_name == "" && middle_name == "" && last_name == "")
	{
		generateRandomName(first_name, middle_name, last_name);
	}
	this->_first_name = first_name;
	this->_middle_name = middle_name;
	this->_last_name = last_name;
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