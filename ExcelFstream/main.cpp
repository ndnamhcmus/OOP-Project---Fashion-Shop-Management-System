#include "ExcelFstream.h"

int main()
{
	ExcelFstream file;
	Product product;
	Staff staff("abc", Date(), "123", Address("123", "123", "123", "123", "123"), "123", 0);


	file.open("Product.csv");
	file.writeExcelFile(staff);
	file.close();
}