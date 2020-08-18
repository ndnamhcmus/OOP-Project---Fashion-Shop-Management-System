#include "ExcelFstream.h"

int main()
{
	ExcelFstream file;
	Product product;


	file.open("Product.csv", ios::in | ios::app);
	file.readExcelFile(product);
	file.close();
}