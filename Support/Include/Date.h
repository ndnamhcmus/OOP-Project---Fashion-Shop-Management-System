#ifndef _DATE_
#define _DATE_


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <chrono>
#include <Tokenizer.h>

using namespace std;

class Date
{
private:

	int _day;
	int _month;
	int _year;

public:

	////		Constuctor		////
	Date(int day = 0, int month = 0, int year = 0);


	////		Methods			////

	void setDay(int day) { _day = day; }

	void setMonth(int month) { _month = month; }

	void setYear(int year) { _year = year; }

	int getDay();

	int getMonth();
	
	int getYear();

	string toString();
	
	static Date parse(const string& date);

	static bool tryParse(const string& s_date = "", Date date = Date(0, 0, 0));

	static bool isValid(const string& date);

	static bool isLeapYear(const int& year);


	////		Operator		////
	friend ostream& operator<<(ostream& out, const Date& date);

	bool operator==(const Date& date);

	bool operator!=(const Date& date);

	bool operator>(const Date& date) {

		if (this->_year > date._year)
			return true;
		if (this->_year == date._year) {
			if (this->_month > date._month)
				return true;
			if (this->_month == date._month)
				if (this->_day > date._day)
					return true;
		}
		return false;
	}

	operator string();
};


#endif // _DATE_