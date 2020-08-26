#include "ExcelFstream.h"


////			EXCEL IN FILE STREAM		////

////		Main read file		////
template <class T>
void ExcelIfstream::readExcelFile(T& object, const string& file_name)
{
	try
	{
		if (!(this->_file_in))
		{
			stringstream writer;
			writer << file_name << " is not open";
			throw ExcelFstreamException(writer.str());
		}
	}
	catch (const exception& mess)
	{
		cout << mess.what() << endl;
		exit(EXIT_FAILURE);
	}


	string buffer;
	while (getline(_file_in, buffer))
	{
		auto container = this->parse(buffer);


		inputToObject(object, container);
	}
}

//void ExcelIfstream::readExcelFile(Account& account, const string& file_name)
//{
//	try
//	{
//		if (!(this->_file_in))
//		{
//			stringstream writer;
//			writer << file_name << " is not open";
//			throw writer.str();
//		}
//	}
//	catch (const string& notification)
//	{
//		cout << notification << endl;
//		exit(EXIT_FAILURE);
//	}
//
//
//	while (!(this->_file_in.eof()))
//	{
//		string buffer;
//		getline(this->_file_in, buffer);
//
//
//		auto container = this->parse(buffer);
//		inputToObject(account, container);
//	}
//}
//
//void ExcelIfstream::readExcelFile(Bill& bill, const string& file_name)
//{
//	try
//	{
//		if (!(this->_file_in))
//		{
//			stringstream writer;
//			writer << file_name << " is not open";
//			throw writer.str();
//		}
//	}
//	catch (const string& notification)
//	{
//		cout << notification << endl;
//		exit(EXIT_FAILURE);
//	}
//
//
//	while (!(_file_in.eof()))
//	{
//		string buffer;
//		getline(_file_in, buffer);
//
//
//		auto container = this->parse(buffer);
//		inputToObject(bill, container);
//	}
//}
//
////void ExcelIfstream::readExcelFile(Seller& seller, const string& file_name)
////{
////	try
////	{
////		if (!(this->_file_in))
////		{
////			stringstream writer;
////			writer << file_name << " is not open";
////			throw writer.str();
////		}
////	}
////	catch (const string& notification)
////	{
////		cout << notification << endl;
////		exit(EXIT_FAILURE);
////	}
////
////
////	while (!(_file_in.eof()))
////	{
////		string buffer;
////		getline(_file_in, buffer);
////
////
////		auto container = this->parse(buffer);
////		inputToObject(seller	, container);
////	}
////}
//
//void ExcelIfstream::readExcelfile(Security& security, const string& file_name)
//{
//	try
//	{
//		if (!(this->_file_in))
//		{
//			stringstream writer;
//			writer << file_name << " is not open";
//			throw writer.str();
//		}
//	}
//	catch (const string& notification)
//	{
//		cout << notification << endl;
//		exit(EXIT_FAILURE);
//	}
//
//
//
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////		Input object		////

void ExcelIfstream::inputToPerson(Person& person, vector<string> container, int& curr_pos)
{
	int i, count = 0;


	for (i = curr_pos, count = 0; count < 4; i++, count++)
	{
		switch (count)
		{
		case 0:
			person._name = container[i];
			break;

		case 1:
			string(person._date_of_birth) = container[i];
			break;

		case 2:
			person._phone_number = container[i];
			break;

		case 3:
			string(person._address) = container[i];
			break;
		}
	}


	curr_pos = i;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ExcelIfstream::inputToObject(Product& product, vector<string> container)
{
	for (int i = 0; i < container.size(); i++)
	{
		switch (i)
		{
		case 0:
			product._product_name = container[i];
			break;

		case 1:
			product._product_type = container[i];
			break;

		case 2:
			product._product_color = container[i];
			break;

		case 3:
			product._product_size = container[i];
			break;

		case 4:
			product._product_id = container[i];
			break;

		case 5:
			product._firm_name = container[i];
			break;

		case 6:
			product._discount = stod(container[i]);
			break;

		case 7:
			product._product_price = stod(container[i]);
			break;

		case 8:
			product._product_cost = stod(container[i]);
			break;

		case 9:
			product._stock_in_time.date = Date::parse(container[i]);
			break;

		case 10:
			product._stock_in_time.time = MyTime::parse(container[i]);
			break;

		case 11:
			product._stock_out_time.date = Date::parse(container[i]);
			break;

		case 12:
			product._stock_out_time.time = MyTime::parse(container[i]);
			break;

		case 13:
			product._stock_cover_time.date = Date::parse(container[i]);
			break;

		case 14:
			product._stock_cover_time.time = MyTime::parse(container[i]);
			break;

		case 15:
			product._quantity_out_of_stock = stoi(container[i]);
			break;
		}
	}
}

void ExcelIfstream::inputToObject(Account& account, vector<string> container)
{
	for (int i = 0; i < container.size(); i++)
	{
		switch (i)
		{
		case 0:
			account._account_id = container[i];
			break;

		case 1:
			inputToPerson(account._customer, container, i);
			break;

		case 5:
			account._customer._customer_id = container[i];
			break;

		case 6:
			account._membership_level._level = container[i];
			break;

		case 7:
			account._membership_level._cumulative_points = stoi(container[i]);
			break;
		}
	}
}

void ExcelIfstream::inputToObject(Bill& bill, vector<string> container)
{
	for (int i = 0; i < container.size(); i++)
	{
		switch (i)
		{
		case 0:
			bill._bill_id = container[i];
			break;

		case 1:
			readExcelFile(bill._product);
			break;

		case 2:
			bill._curr_date = Date::parse(container[i]);
			break;
		}
	}
}

void ExcelIfstream::inputToObject(Security& security, vector<string> container)
{
	for (int i = 0; i < container.size(); i++)
	{
		switch (i)
		{
		case 0:
			security._staff_id = container[i];
			break;

		case 1:
			inputToPerson(security, container, i);
			break;

		case 5:
			security._base_salary = stod(container[i]);
			break;
		}
	}
}

//void ExcelIfstream::inputToObject(Seller& seller, vector<string> container)
//{
//
//}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<string> ExcelIfstream::parse(const string& line)
{
	auto container = Tokenizer::parse(line, ",");
	return container;
}

void ExcelIfstream::open(string directory, ios_base::openmode mode)
{
	for (int i = 0; i < directory.size(); i++)
	{
		if (directory[i] == '/')
		{
			directory.insert(i, "/");
		}
	}
	this->_file_in.open(directory, mode | ios::app);
}

void ExcelIfstream::close()
{
	this->_file_in.close();
}


////		EXCEL OUT FILE STREAM		////

////		Main write file		///

void ExcelOfstream::writeExcelFile(Product product, const string& file_name)
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


	////		Lưu tạm vào buffer để kiểm tra		////
	stringstream buffer;

	buffer << product._product_name << "," << product._product_type << "," << product._product_color << "," << product._product_size << "," << product._product_id << "," << product._firm_name << ",";
	buffer << to_string(product._discount) << "," << to_string(product._product_price) << "," << to_string(product._product_cost) << ",";
	buffer << string(product._stock_in_time.date) << "," << product._stock_in_time.time.toString() << "," << string(product._stock_out_time.date) << "," << product._stock_out_time.time.toString() << "," << string(product._stock_cover_time.date) << "," << product._stock_cover_time.time.toString() << ",";
	buffer << product._quantity_out_of_stock << endl;


	////		Save to file		////
	_file_out << buffer.str();
}

void ExcelOfstream::writeExcelFile(Account account, const string& file_name)
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


	stringstream buffer;
	buffer << account._account_id << ",";
	inputBuffer(account._customer);
	inputBuffer(account._membership_level);


	_file_out << buffer.str();
}


////		TO DO: Seller đang viết dở		/////

//void ExcelOfstream::writeExcelFile(Seller seller, const string& file_name)
//{
//	try
//	{
//		if (!(this->_file_out))
//		{
//			stringstream writer;
//			writer << file_name << " is not open";
//			throw string(writer.str());
//		}
//	}
//	catch (const string& notification)
//	{
//		cout << notification << endl;
//		exit(EXIT_FAILURE);
//	}
//
//
//	writeStaffInfoToExcelFile(seller);
//	_file_out << seller._goods_sale << "," << seller._commission << "," << seller._real_salary << ",";
//	_file_out << endl;
//}

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


	stringstream buffer;
	buffer << security._staff_id << ",";
	inputPersonToBuffer(security);
	buffer << security._base_salary << ",";


	_file_out << buffer.str();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////		Input buffer		////

void ExcelOfstream::inputPersonToBuffer(Person person)
{
	_buffer << person._name << "," << string(person._date_of_birth) << "," << person._phone_number << "," << string(person._address) << ",";
}

void ExcelOfstream::inputBuffer(Customer customer)
{
	inputPersonToBuffer(customer);
	_buffer << customer._customer_id << ",";
}
		  
void ExcelOfstream::inputBuffer(MembershipLevel membership_level)
{
	_buffer << membership_level._level << "," << membership_level._cumulative_points << ",";
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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


////		EXCEL IN/OUT FILE STREAM		////


void ExcelFstream::open(string directory, ios_base::openmode mode)
{
	ExcelOfstream::open(directory, mode);
	ExcelIfstream::open(directory, mode);
}

void ExcelFstream::close()
{
	ExcelOfstream::close();
	ExcelIfstream::close();
}
