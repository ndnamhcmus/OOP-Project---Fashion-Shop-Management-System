#include <iostream>
#include <string>
#include <fstream>
#include <Product.h>
#include <Account.h>
#include <FakeAddress.h>

using namespace std;

class ExcelFstream
{
private:

	fstream f;

public:

	void readExcelFile(Product& product);
	void writeExcelFile(Product& product);

	void readExcelFile(Account& account);
	void writeExcelFile(Account& account);

	void readExcelFile(Bill& bill);
	void writeExcelfile(Bill& bill);

	void readExcelFile(Staff staff);
	void readExcelFile(Staff staff);
};

