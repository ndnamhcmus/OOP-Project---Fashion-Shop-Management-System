#ifndef _FAKE_BIRTHDAY_
#define _FAKE_BIRTHDAY_


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <Date.h>

using namespace std;

class FakeBirthday
{
private:

	int _day;
	int _month;
	int _year;
	int _age;

public:

	////		Constructor		////
	FakeBirthday(int day = 0, int month = 0, int year = 0, int age = 0);

	////		Method		////
	Date next();

	int getAge();
};


#endif // !_FAKE_BIRTHDAY_