#include "Date.h"

int main()
{
	srand(time(0));
	

	Date curr_date;
	cout << "Current date: ";
	cout << curr_date << endl;


	int day, month, year;
	cin >> day >> month >> year;
	Date set_date(day, month, year);
	cout << "Set up date: ";
	cout << set_date << endl;


	cout << "Convert Date to string: ";
	cout << curr_date.toString() << endl;


	cout << "Convert string to Date: ";
	cout << Date::parse("30/04/1975") << endl;


	cout << "Is 32/20/0 valid?. Answer: ";
	if (Date::isValid("32/20/0"))
	{
		cout << "Valid\n";
	}
	else
	{
		cout << "Invalid\n";
	}


	cout << "2001 is a leap year? Answer: ";
	if (Date::isLeapYear(2001))
	{
		cout << "Is a leap year\n";
	}
	else
	{
		cout << "Is not a leap year\n";
	}


	cout << "Try to parse: 00/00\n";
	if (Date::tryParse("00/00/00", Date(0,0,1)))
	{
		cout << "Success\n";
	}
	else
	{
		cout << "Fail\n";
	}
	

	system("pause");
	return 0;
}