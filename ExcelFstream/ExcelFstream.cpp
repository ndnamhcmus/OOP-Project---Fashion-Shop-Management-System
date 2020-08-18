#include "ExcelFstream.h"


////		EXCEL FILE STREAM			////


fstream& operator<<(fstream& file, const Product& product)
{
	file << product._product_name << "," << product._product_type << "," << product._product_color << "," << product._product_size << "," << product._product_id << "," << product._firm_name << ",";
	file << product._discount << "," << product._product_price << "," << product._product_cost << ",";
	file << product._stock_in_time.date << " " << product._stock_in_time.time << "," << product._stock_out_time.date << " " << product._stock_out_time.time << "," << product._stock_cover_time.date << " " << product._stock_cover_time.time << ",";
	file << product._quantity_out_of_stock;
	return file;
}

fstream& operator>>(fstream& file, Product& product)
{
	int check = 0;
	while (!(file.eof()))
	{
		string temp;
		getline(file, temp, ',');
		++check;


		switch (check)
		{
		case 1:
			product._product_name = temp;
			break;

		case 2:
			product._product_type = temp;
			break;

		case 3:
			product._product_color = temp;
			break;

		case 4:
			product._product_size = temp;
			break;

		case 5:
			product._product_id = temp;
			break;

		case 6:
			product._firm_name = temp;
			break;

		case 7:
			product._discount = stod(temp);
			break;

		case 8:
			product._product_price = stod(temp);
			break;

		case 9:
			product._product_cost = stod(temp);
			break;

		case 10:
			product._stock_in_time.date.toString() = temp;
			break;

		case 11:
			product._stock_in_time.time.toString() = temp;
			break;

		case 12:
			product._stock_out_time.date.parse(temp);
			break;

		case 13:
			product._stock_out_time.time.toString() = temp;
			break;

		case 14:
			product._stock_cover_time.date.toString() = temp;
			break;

		case 15:
			product._stock_cover_time.time.toString() = temp;
			break;

		case 16:
			product._quantity_out_of_stock = stoi(temp);
			break;
		}
	}
	return file;
}


////			EXCEL IN FILE STREAM		////


void ExcelIfstream::open(string directory, ios_base::openmode mode)
{
	for (int i = 0; i < directory.size(); i++)
	{
		if (directory[i] == '/')
		{
			directory.insert(i, "/");
		}
	}
	this->_file_in.open(directory, mode);
}

void ExcelIfstream::close()
{
	this->_file_in.close();
}

void ExcelIfstream::readExcelFile(Product& product, const string& file_name)
{
	try
	{
		if (!(this->_file_in))
		{
			stringstream writer;
			writer << file_name << " is not open";
			throw writer.str();
		}
	}
	catch (const string& notification)
	{
		cout << notification << endl;
		exit(EXIT_FAILURE);
	}


	this->_file_in >> product;
}

void ExcelIfstream::readExcelFile(Product& product, const string& file_name)
{
	try
	{
		if (!(this->_file_in))
		{
			stringstream writer;
			writer << file_name << " is not open";
			throw writer.str();
		}
	}
	catch (const string& notification)
	{
		cout << notification << endl;
		exit(EXIT_FAILURE);
	}


	this->_file_in >> product;
}

void ExcelIfstream::readExcelFile(Account& account)
{
}

void ExcelIfstream::readExcelFile(Bill& bill)
{
}

void ExcelIfstream::readExcelFile(Staff staff)
{
}

ifstream& operator>>(ifstream& file_in, Product& product)
{
	int check = 0;
	while (!(file_in.eof()))
	{
		string temp;
		getline(file_in, temp, ',');
		++check;


		switch (check)
		{
		case 1:
			product._product_name = temp;
			break;

		case 2:
			product._product_type = temp;
			break;

		case 3:
			product._product_color = temp;
			break;

		case 4:
			product._product_size = temp;
			break;

		case 5:
			product._product_id = temp;
			break;

		case 6:
			product._firm_name = temp;
			break;

		case 7:
			product._discount = stod(temp);
			break;

		case 8:
			product._product_price = stod(temp);
			break;

		case 9:
			product._product_cost = stod(temp);
			break;

		case 10:
			product._stock_in_time.date.toString() = temp;
			break;

		case 11:
			product._stock_in_time.time.toString() = temp;
			break;

		case 12:
			product._stock_out_time.date.parse(temp);
			break;

		case 13:
			product._stock_out_time.time.toString() = temp;
			break;

		case 14:
			product._stock_cover_time.date.toString() = temp;
			break;

		case 15:
			product._stock_cover_time.time.toString() = temp;
			break;

		case 16:
			product._quantity_out_of_stock = stoi(temp);
			break;
		}
	}
	return file_in;
}


////		EXCEL OUT FILE STREAM		////


void ExcelOfstream::open(string directory, ios_base::openmode mode)
{
	for (int i = 0; i < directory.size(); i++)
	{
		if (directory[i] == '/')
		{
			directory.insert(i, "/");
		}
	}
	this->_file_out.open(directory, mode);
}

void ExcelOfstream::close()
{
	this->_file_out.close();
}

void ExcelOfstream::writeExcelFile(Product& product, const string& file_name)
{
	try
	{
		if (!(this->_file_out))
		{
			stringstream writer;
			writer << file_name << " is not open";
			throw string(writer.str());
		}
	}
	catch (const string& notification)
	{
		cout << notification << endl;
		exit(EXIT_FAILURE);
	}



	this->_file_out << product;
	this->_file_out << endl;
}

void ExcelOfstream::writeExcelFile(Product& product, const string& file_name)
{
	try
	{
		if (!(this->_file))
		{
			stringstream writer;
			writer << file_name << " is not open";
			throw string(writer.str());
		}
	}
	catch (const string& notification)
	{
		cout << notification << endl;
		exit(EXIT_FAILURE);
	}



	this->_file << product;
	this->_file << endl;
}

void ExcelOfstream::writeExcelFile(Account& account)
{
}
		  
void ExcelOfstream::writeExcelfile(Bill& bill)
{
}
		 
void ExcelOfstream::writeExcelFile(Staff staff)
{
}

ofstream& operator<<(ofstream& file_out, const Product& product)
{
	file_out << product._product_name << "," << product._product_type << "," << product._product_color << "," << product._product_size << "," << product._product_id << "," << product._firm_name << ",";
	file_out << product._discount << "," << product._product_price << "," << product._product_cost << ",";
	file_out << product._stock_in_time.date << " " << product._stock_in_time.time << "," << product._stock_out_time.date << " " << product._stock_out_time.time << "," << product._stock_cover_time.date << " " << product._stock_cover_time.time << ",";
	file_out << product._quantity_out_of_stock;
	return file_out;
}