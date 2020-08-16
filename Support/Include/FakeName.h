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
	FullName();

	///		Get data function	///
	string getFirstName();
	string getMiddleName();
	string getLastName();


	string FullName_to_string();


	///		Operator	///
	//friend ostream& operator<<(ostream& out, const FullName& name);

	operator string();
};

class FakeName
{
public:
	static FullName next();
};