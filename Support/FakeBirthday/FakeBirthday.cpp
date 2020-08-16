#include "FakeBirthday.h"

FakeBirthday::FakeBirthday(int day, int month, int year, int age)
{
	if (!day && !month && !year && !age)
	{
		/*stringstream writer;
		writer << to_string(day) << "/" << to_string(month) << "/" << to_string(year);
		string s_date = writer.str();
		Date date;*/


		Date date;
		string s_date;
		do
		{
			age = 0 + rand() % (116 - 0 + 1);


			day = 1 + rand() % (31 - 1 + 1);
			month = 1 + rand() % (12 - 1 + 1);
			year = date.getYear() - age;


			Date date(day, month, year);
			s_date = string(date);

		} while (!Date::isValid(s_date));
	}
	this->_day = day;
	this->_month = month;
	this->_year = year;
	this->_age = age;
}

Date FakeBirthday::next()
{
	return Date(this->_day, this->_month, this->_year);
}

int FakeBirthday::getAge()
{
	return this->_age;
}
