#ifndef _FAKE_NAME_
#define _FAKE_NAME_


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class FullName
{
private:
	string _first_name;
	string _middle_name;
	string _last_name;

public:
	FullName(string first_name = "", string middle_name = "", string last_name = "");

	///		Get data function	///
	string getFirstName();
	string getMiddleName();
	string getLastName();

	string FullName_to_string();

	void readFile();


	///		Operator	///
	//friend ostream& operator<<(ostream& out, const FullName& name);

	operator string();
};

class FakeName
{
public:
	static FullName next();
};


#endif // !_FAKE_NAME_