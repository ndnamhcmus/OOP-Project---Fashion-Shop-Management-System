#include "Time.h"

int main()
{
	int hour, minute, second;
	cin >> hour >> minute >> second;


	Time time(hour, minute, second);
	cout << "24 hour mode: " << time.toString() << endl;
	cout << "12 hour mode: " << time.AmPmMode() << endl << endl;


	cout << "Convert string 12:00:00 to int\n";	
	cout << time.parse("12:00:00") << endl << endl;


	cout << "Is 24:-0:60 valid?\n";
	if (Time::isValid("24:-0:60"))
	{
		cout << "Valid\n";
	}
	else
	{
		cout << "Invalid\n";
	}
	cout << "Is 12:00:00 valid?\n";
	if (Time::isValid("12:00:00"))
	{
		cout << "Valid\n";
	}
	else
	{
		cout << "Invalid\n";
	}
	cout << endl;


	cout << "Try to parse 12:00:00\n";
	if (Time::tryParse("12:00:00"))
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