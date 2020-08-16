﻿#ifndef _FAKE_ADDRESS_
#define _FAKE_ADDRESS_


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class FakeHouseNumber
{
public:
	static string generateRandomHouseNumber();
};

class Address
{
private:
	string _number = FakeHouseNumber::generateRandomHouseNumber();
	string _street;
	string _ward;
	string _district;
	string _city; 

public:
	Address();
	string get_Number();
	string get_Street();
	string get_Ward();
	string get_District();
	string get_City();


	string Address_to_string();


	////		Operators		////
	operator string();

	friend ostream& operator<<(ostream& out, Address address);
};

class FakeHCMAddress
{
public:
	static Address next();
};


#endif // !_FAKE_ADDRESS_