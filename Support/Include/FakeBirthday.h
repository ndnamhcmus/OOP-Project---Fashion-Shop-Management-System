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

	static int _age;

private:

	static Date generateFakeBirthday();

public:		////		Method		////
	static Date next();

	static int getAge();
};


#endif // !_FAKE_BIRTHDAY_