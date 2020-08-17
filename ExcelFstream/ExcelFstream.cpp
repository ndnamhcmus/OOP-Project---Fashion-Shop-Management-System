#include "ExcelFstream.h"

void ExcelFstream::readExcelFile(Product& product)
{
}

void ExcelFstream::writeExcelFile(Product& product)
{
	ofstream file_out;
	file_out.open("Product.csv", ios::out | ios::app);
	try
	{
		if (!file_out)
		{
			throw string("File is not open");
		}
	}
	catch (const string& error)
	{
		cout << error << endl;
		exit(EXIT_FAILURE);
	}
	
	int count = 0;
	while (count <= 1)
	{
		/*file_out << product._product_name << "," << product._product_type << "," << product._product_color << "," << product._product_size << "," << product._product_id << "," << product._firm_name << ","
			<< product._discount << "," << product._product_price << "," << product._product_cost << ","
			<< product._stock_in_time.date << " " << product._stock_in_time.time << "," << product._stock_out_time.date << " " << product._stock_out_time.time << "," << product._stock_cover_time.date << " " << product._stock_cover_time.time << ","
			<< product._quantity_out_of_stock;*/

		file_out << "abc" << "," << "def" << " " << "hik" << endl;
		count++;
	}
	file_out.close();
}

void ExcelFstream::readExcelFile(Account& account)
{
}

void ExcelFstream::writeExcelFile(Account& account)
{
}

void ExcelFstream::readExcelFile(Bill& bill)
{
}

void ExcelFstream::writeExcelfile(Bill& bill)
{
}

void ExcelFstream::readExcelFile(Staff staff)
{
}

void ExcelFstream::writeExcelFile(Staff staff)
{
}
