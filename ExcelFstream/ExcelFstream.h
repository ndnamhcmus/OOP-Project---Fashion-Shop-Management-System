#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <Product.h>
#include <Account.h>
#include <FakeAddress.h>

using namespace std;

class ExcelIfstream
{
protected:

	ifstream _file_in;

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



	////		Operator		////
	friend ifstream& operator>>(ifstream& file_in, Product& product);

	friend ifstream& operator>>(ifstream& file_in, Account& account);
};

class ExcelOfstream
{
protected:

	ofstream _file_out;

public:

	~ExcelOfstream()
	{
		_file_out.close();
	}


	void open(string directory, ios_base::openmode mode = ios::out);
	void close();

	void writeExcelFile(Product& product, const string& file_name = "Product.csv");

	void writeExcelFile(Account& account);

	void writeExcelfile(Bill& bill);

	void writeExcelFile(Staff staff);


	////		Operator		////
	friend ofstream& operator<<(ofstream& file_out, const Product& product);

	friend ofstream& operator<<(ofstream& file_out, const Account& account);

	friend ofstream& operator<<(ofstream& file_out, const Person& person);
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

	////		Operator		////
	friend fstream& operator<<(fstream& file, const Product& product);

	friend fstream& operator>>(fstream& file, Product& product);
};

