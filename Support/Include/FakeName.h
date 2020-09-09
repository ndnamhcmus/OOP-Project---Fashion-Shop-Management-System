#ifndef _FAKE_NAME_
#define _FAKE_NAME_


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <Random.h>

using namespace std;

class FullName
{
private:

	string _first_name_list[16] = { "Nguyen", "Tran", "Le", "Pham", "Hoang", "Huynh", "Phan", "Vu", "Vo", "Dang", "Bui", "Do", "Ho", "Ngo", "Duong", "Ly"};
	string _middle_name_list[12] = { "Dinh", "Van", "Hung", "Kim", "Thi", "Dieu", "Nu", "Dinh", "Ba", "Trong", "Manh", "Thuc" };
	string _last_name_list[19] = { "Ha", "Hai", "Hanh", "Hao", "Lu", "Nam", "Minh", "Nghia", "Nghiem", "Su", "Tam", "Thao", "Thi", "Truc", "Phuoc", "Tu", "Viet", "Vy", "Yen" };

private:
	string _first_name;
	string _middle_name;
	string _last_name;

private:

	void generateRandomName(string& first_name, string& middle_name, string& last_name);

public:

	FullName(string first_name = "", string middle_name = "", string last_name = "");

public:
	///		Get data function	///
	string getFirstName();
	string getMiddleName();
	string getLastName();

public:

	string FullName_to_string();

public:

	operator string();
};

class FakeName
{
public:
	static FullName next();
};


#endif // !_FAKE_NAME_