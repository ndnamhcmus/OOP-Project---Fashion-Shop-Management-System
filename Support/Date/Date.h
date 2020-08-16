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

	operator string();
};


#endif // !_DATE_