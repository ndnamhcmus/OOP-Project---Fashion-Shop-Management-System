#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <Product.h>
#include <Account.h>
#include <Bill.h>
#include <Person_Customer_Staff_Seller_Security.h>
#include <FakeAddress.h>
/////
using namespace std;

class ExcelIfstream
{
protected:

	ifstream _file_in;

	void readExcelFile(Customer& customer, const string& file_name = "Product.csv");

public:

	~ExcelIfstream()
	{
		_file_in.close();
	}



	////		Method		////
	void open(string directory, ios_base::openmode mode = ios::in);

	void close();



	void readExcelFile(Product& product, const string& file_name = "Product.csv");

	void readExcelFile(Account& account, const string& file_name = "Account.csv");

	void readExcelFile(Bill& bill, const string& file_name = "Bill.csv");

	void readExcelFile(Staff staff, const string& file_name = "Staff.csv");
};

class ExcelOfstream
{
protected:

	ofstream _file_out;

	void writePersonToExcelFile(Person person);

	void writeExcelFile(Customer customer);

	void writeExcelFile(MembershipLevel membership_level);

	void writeStaffInfoToExcelFile(Staff staff);
	

public:

	~ExcelOfstream()
	{
		_file_out.close();
	}


	////		OPEN/CLOSE		////
	void open(string directory, ios_base::openmode mode = ios::out);

	void close();


	////		Write file		////
	void writeExcelFile(const Product& product, const string& file_name = "Product.csv");

	void writeExcelFile(const Account& account, const string& file_name="Account.csv");
						
	void writeExcelfile(Bill bill, const string& file_name = "Bill.csv");
						
	void writeExcelFile(Seller seller, const string& file_name = "Staff.csv");

	void writeExcelFile(Security security, const string& file_name = "Staff.csv");
};

class ExcelFstream : public ExcelIfstream, public ExcelOfstream
{
private:

	fstream _file;

public:
	~ExcelFstream()
	{
		_file.close();
	}

	void open(string directory, ios_base::openmode mode = 0);

	void close();
};