#include "FakeBirthday.h"

int FakeBirthday::_age = 0;

Date FakeBirthday::generateFakeBirthday()
{
	string s_date;
	do
	{
		int age = 0 + rand() % (116 - 0 + 1);
		_age = age;


		Date date;
		int day = 1 + rand() % (31 - 1 + 1);
		int month = 1 + rand() % (12 - 1 + 1);
		int year = date.getYear() - age;


		Date date_of_birth(day, month, year);


		s_date = string(date_of_birth);
		if (Date::isValid(s_date))
		{
			return date_of_birth;
		}
	} while (!Date::isValid(s_date));
}

Date FakeBirthday::next()
{
	return generateFakeBirthday();
}

int FakeBirthday::getAge()
{
	return _age;
}
