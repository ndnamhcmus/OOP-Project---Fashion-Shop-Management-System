#ifndef _FAKE_VN_TEL_
#define _FAKE_VN_TEL_


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class FakeVnTel
{
private:
	string _tel;
public:
	FakeVnTel();
	string getVnTel();
};


#endif // !_FAKE_VN_TEL_