#ifndef _FAKE_TEL_
#define _FAKE_TEL_


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <Random.h>

using namespace std;

class FakeVnTel
{
private:

	string _telephone_number;

	void readFile();

public:
	FakeVnTel(string telephone_number = "");

public:
	void generateRandomPhoneNumber();

	string toString();

public:
	operator string();
};


class FileException : public exception
{
private:

	string _exception_mess;

public:

	FileException(const string& exception_mess)
	{
		this->_exception_mess = exception_mess;
	}

public:

	const char* what() const throw()
	{
		return _exception_mess.c_str();
	}
};



#endif // !_FAKE_TEL_