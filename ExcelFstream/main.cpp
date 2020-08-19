#include "ExcelFstream.h"

int main()
{
	ExcelFstream file;
	Product product;
	Seller seller("name", Date(22,11,2001), "phone_num", Address("num", "street", "ward", "district", "city"), "ID", 0, 1, 2, 3);


	file.open("Staff.csv", ios::app);
	file.writeExcelFile(seller);
	file.close();
}