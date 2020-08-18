#include "ExcelFstream.h"

int main()
{
	ExcelFstream file;
	Product product;


	file.open("Product.csv");
	file.readExcelFile(product);
	file.close();
}