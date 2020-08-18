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
private:

	ifstream _file_in;

public:

	////		Method		////
	void open(string directory, ios_base::openmode mode);
	void close();

	void readExcelFile(Product& product, const string& file_name = "Product.csv");

	void readExcelFile(Account& account);

	void readExcelFile(Bill& bill);

	void readExcelFile(Staff staff);

	friend ifstream& operator>>(ifstream& file_in, Product& product);
};


class ExcelOfstream
{
private:

	ofstream _file_out;

public:

	void open(string directory, ios_base::openmode mode);
	void close();

	void writeExcelFile(Product& product, const string& file_name = "Product.csv");

	void writeExcelFile(Account& account);

	void writeExcelfile(Bill& bill);

	void writeExcelFile(Staff staff);

	friend ofstream& operator<<(ofstream& file_out, const Product& product);
};

class ExcelFstream : public ExcelOfstream, ExcelIfstream
{
private:

	fstream _file;

public:
	////		Operator		////
	friend fstream& operator<<(fstream& file, const Product& product);
	friend fstream& operator>>(fstream& file, Product& product);
};

