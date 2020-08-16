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

