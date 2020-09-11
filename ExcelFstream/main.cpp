#include "ExcelFstream.h"

int main()
{
	ExcelFstream file;
	file.open("test.csv", ios::app);
	file.writeExcelString("Nguyen - Duc - Nam");
	file.close();

	
	file.open("test.csv", ios::app);
	vector <vector <string>> container;
	file.readExcelString(container);


	file.close();



	system("pause");
	return 0;
}