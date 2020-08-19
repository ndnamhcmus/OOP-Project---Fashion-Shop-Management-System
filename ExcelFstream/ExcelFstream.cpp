#include "ExcelFstream.h"


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


	int check = 0;
	while (!(this->_file_in.eof()))
	{
		string temp;
		getline(this->_file_in, temp, ',');
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
			product._stock_in_time.date = Date::parse(temp);
			break;

		case 11:
			product._stock_in_time.time = MyTime::parse(temp);
			break;

		case 12:
			product._stock_out_time.date = Date::parse(temp);
			break;

		case 13:
			product._stock_out_time.time = MyTime::parse(temp);
			break;

		case 14:
			product._stock_cover_time.date = Date::parse(temp);
			break;

		case 15:
			product._stock_cover_time.time = MyTime::parse(temp);
			break;

		case 16:
			product._quantity_out_of_stock = stoi(temp);
			break;
		}
	}
}

void ExcelIfstream::readExcelFile(Account& account, const string& file_name)
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


	int check = 0;
	while (!(this->_file_in.eof()))
	{
		string temp;
		getline(this->_file_in, temp, ',');
		++check;


		switch (check)
		{
		case 1:
			account._account_id = temp;
			break;
		}
	}
}

void ExcelIfstream::readExcelFile(Customer& customer, const string& file_name)
{
	getline(_file_in, customer._customer_id, ',');
}

void ExcelIfstream::readExcelFile(Bill& bill, const string& file_name)
{
}

void ExcelIfstream::readExcelFile(Staff staff, const string& file_name)
{
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
	this->_file_out.open(directory, mode | ios::app);
}

void ExcelOfstream::close()
{
	this->_file_out.close();
}

void ExcelOfstream::writeExcelFile(const Product& product, const string& file_name)
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



	_file_out << product._product_name << "," << product._product_type << "," << product._product_color << "," << product._product_size << "," << product._product_id << "," << product._firm_name << ",";
	_file_out << product._discount << "," << product._product_price << "," << product._product_cost << ",";
	_file_out << product._stock_in_time.date << "," << product._stock_in_time.time << "," << product._stock_out_time.date << "," << product._stock_out_time.time << "," << product._stock_cover_time.date << "," << product._stock_cover_time.time << ",";
	_file_out << product._quantity_out_of_stock;
}

void ExcelOfstream::writeExcelFile(const Account& account, const string& file_name)
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


	_file_out << account._account_id << ",";
	writeExcelFile(account._customer);
	writeExcelFile(account._membership_level);
}
		  
void ExcelOfstream::writeExcelfile(Bill bill, const string& file_name)
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


	_file_out << bill._bill_id << ",";
	writeExcelFile(bill._product);
	_file_out << string(bill._curr_date) << ",";
}
		 
void ExcelOfstream::writePersonToExcelFile(Person person)
{
	_file_out << person._name << "," << string(person._date_of_birth) << "," << person._phone_number << "," << string(person._address) << ",";
}

void ExcelOfstream::writeExcelFile(Customer customer)
{
	writePersonToExcelFile(customer);
	_file_out << customer._customer_id << ",";
}

void ExcelOfstream::writeExcelFile(MembershipLevel membership_level)
{
	_file_out << membership_level._level << "," << membership_level._cumulative_points << ",";
}

void ExcelOfstream::writeStaffInfoToExcelFile(Staff staff)
{
	_file_out << staff._staff_id << ",";
	writePersonToExcelFile(staff);
	_file_out << staff._base_salary << ",";
}

void ExcelOfstream::writeExcelFile(Seller seller, const string& file_name)
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
	

	writeStaffInfoToExcelFile(seller);
	_file_out << seller._goods_sale << "," << seller._commission << "," << seller._real_salary << ",";
	_file_out << endl;
}

void ExcelOfstream::writeExcelFile(Security security, const string& file_name)
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


	_file_out << security._staff_id << ",";
	writePersonToExcelFile(security);
	_file_out << security._base_salary << ",";
}


////		EXCEL IN/OUT FILE STREAM		////


void ExcelFstream::open(string directory, ios_base::openmode mode)
{
	if (mode == ios::out)
	{
		_file_out.open(directory, mode);
	}
	else if (mode == ios::in)
	{
		_file_in.open(directory, mode);
	}
	else
	{
		_file_out.open(directory, mode);
		_file_in.open(directory, mode);
	}
}

void ExcelFstream::close()
{
	_file.close();
}
