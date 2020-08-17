#include "ExcelFstream.h"

void ExcelFstream::readExcelFile(Product& product)
{
}

void ExcelFstream::writeExcelFile(Product& product)
{
	ofstream file_out;
	file_out.open("Product.csv", ios::out);

}
