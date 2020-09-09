#include "Date.h"

Date::Date(int day, int month, int year)
{
	if (!year && !month && !day)
	{
		time_t info = time(0);
		tm* time_now = new tm;
		localtime_s(time_now, &info);


		year = time_now->tm_year + 1900;
		month = time_now->tm_mon + 1;
		day = time_now->tm_mday;
	}
	this->_year = year;
	this->_month = month;
	this->_day = day;
}

int Date::getDay()
{
	return this->_day;
}

int Date::getMonth()
{
	return this->_month;
}

int Date::getYear()
{
	return this->_year;
}

string Date::toString()
{
	string s_day = to_string(this->_day);
	string s_month = to_string(this->_month);
	string s_year = to_string(this->_year);


	if (s_day.length() < 2)
	{
		s_day.insert(0, "0");
	}
	if (s_month.length() < 2)
	{
		s_month.insert(0, "0");
	}
	if (s_year.length() < 4)
	{
		s_year.insert(0, "0");
	}
	stringstream writer;
	writer << s_day << "/" << s_month << "/" << s_year;
	return writer.str();
}

Date Date::parse(const string& date)
{
	vector <string> temp = Tokenizer::parse(date, "/");
	return Date(stoi(temp[0]), stoi(temp[1]), stoi(temp[2]));
}

bool Date::tryParse(const string& s_date, Date date)
{
	if (s_date != "")
	{
		vector <string> temp = Tokenizer::parse(s_date, "/");
		if (temp.size() != 3)
		{
			return false;
		}
	}
	if (date != Date())
	{
		vector <string> temp = Tokenizer::parse(date.toString(), "/");
		if (temp.size() != 3)
		{
			return false;
		}
	}

	return true;
}

bool Date::isValid(const string& date)
{
	int count = 0;
	////		kiểm tra form		////
	for (int i = 0; i < date.length(); i++)
	{
		if ((i + 1) % 3)
		{
			if (date[i] < '0' || date[i] > '9')
			{
				return false;
			}
		}
		else
		{
			if (date[i] != '/' && count < 2)
			{
				return false;
			}
			++count;
		}
	}

	////		kiểm tra giới hạn		////
	Date date_to_check = parse(date);
	if (date_to_check._year <= 0)
	{
		return false;
	}
	if (date_to_check._month < 0 || date_to_check._month > 12)
	{
		return false;
	}
	if (date_to_check._day < 0 || date_to_check._day > 31)
	{
		return false;
	}


	if (date_to_check._month == 2)
	{
		if (isLeapYear(date_to_check._year))
		{
			if (date_to_check._day > 29)
			{
				return false;
			}
		}
		else
		{
			if (date_to_check._day > 28)
			{
				return false;
			}
		}
	}
	else if (date_to_check._month == 4 || date_to_check._month == 6 || date_to_check._month == 9 || date_to_check._month == 11)
	{
		if (date_to_check._day > 30)
		{
			return false;
		}

	}
	else
	{
		if (date_to_check._day > 31)
		{
			return false;
		}
	}
	return true;
}

bool Date::isLeapYear(const int& year)
{
	if (!(year % 4) || !(year % 100) && year % 4)
	{
		return true;
	}
	return false;
}

bool Date::operator==(const Date& date)
{
	if (this->_day == date._day && this->_month == date._month && this->_year == date._year)
	{
		return true;
	}
	return false;
}

bool Date::operator!=(const Date& date)
{
	if (*this == date)
	{
		return false;
	}
	return true;
}

Date::operator string()
{
	string s_day = to_string(this->_day);
	string s_month = to_string(this->_month);
	string s_year = to_string(this->_year);


	if (s_day.length() < 2)
	{
		s_day.insert(0, "0");
	}
	if (s_month.length() < 2)
	{
		s_month.insert(0, "0");
	}
	if (s_year.length() < 4)
	{
		s_year.insert(0, "0");
	}
	stringstream writer;
	writer << s_day << "/" << s_month << "/" << s_year;
	return writer.str();
}

Date& Date::operator=(const Date& date)
{
	this->_day = date._day;
	this->_month = date._month;
	this->_year = date._year;

	return *this;
}

ostream& operator<<(ostream& out, const Date& date)
{
	out << date._day << "/" << date._month << "/" << date._year;
	return out;
}