#ifndef _FAKE_ADDRESS_
#define _FAKE_ADDRESS_


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <Random.h>

using namespace std;

class FakeHouseNumber
{
public:

	static string generateRandomHouseNumber();

};

class Address
{

private:

	string _street_list[25] = { "Alexandre de Rhodes", "Cao Ba Nha", "Calmette", "Nguyen Huu Canh", "Ly Thai To", "Tran Phu", "Tran Hung Dao", "Nguyen Thi Nho", "Nguyen Chi Thanh", "Hung Vuong", "Ba Hat", "Ly Thuong Kiet", "Su Van Hanh", "To Hien Thanh", "Thanh Thai", "Tran Huu Trang", "Tran Cao Van", "Cao Thang", "Truong Sa", "Phan Dinh Phung", "Dinh Bo Linh", "Chu Van An", "Le Truc", "Nguyen Van Lac", "Nguyen Xi" };
	string _ward_list[23] = { "Ben Nghe ward", "Ben Thanh ward", "Cau Kho ward", "Cau Ong Lang ward", "Co Giang ward", "Dao Kao ward", "Nguyen Thai Binh ward", "Pham Ngu Lao ward", "Ward 1", "Ward 2","Ward 3","Ward 4","Ward 5","Ward 6","Ward 7","Ward 8","Ward 9","Ward 11","Ward 11","Ward 12","Ward 13","Ward 14","Ward 15" };
	string _district_list[5] = { "District 1", "District 5", "District 10", "Phu Nhuan district", "Binh Thanh district" };


private:

	string _number = FakeHouseNumber::generateRandomHouseNumber();
	string _street;
	string _ward;
	string _district;
	string _city; 

public:

	Address(string number = "", string street = "", string ward = "", string district = "", string city = "Ho Chi Minh city");

public:
	////		Method		////
	string get_Number();
	string get_Street();
	string get_Ward();
	string get_District();
	string get_City();

	string toString();

	Address generateRandomAddress();

public:
	////		Operators		////
	operator string();

	friend ostream& operator<<(ostream& out, Address address);

	Address operator=(const Address& address);

	bool operator==(const Address& address);
};

class FakeHCMAddress
{
public:
	static Address next();
};


#endif // !_FAKE_ADDRESS_