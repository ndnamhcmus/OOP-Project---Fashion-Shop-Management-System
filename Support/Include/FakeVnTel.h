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
	string _header_list[30] = { "086", "096", "097", "098", "032", "033", "034", "035", "036", "037", "038", "039", "089", "090", "093", "070", "079", "077", "076", "078", "088", "091", "094", "083", "084", "085", "081", "082", "099", "059" };
		

private:

	string _telephone_number;

	void generateRandomHeader(string& telephone_number);

public:
	FakeVnTel(string telephone_number = "");

public:
	void generateRandomPhoneNumber(string& telephone_number);

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