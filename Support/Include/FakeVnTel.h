#ifndef _FAKE_TEL_
#define _FAKE_TEL_


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class FakeVnTel
{
private:
	string _telephone_number;
public:
	FakeVnTel(string telephone_number = "");

	string getVnTel();

	operator string();

	void readFile();
};


#endif // !_FAKE_TEL_