//#include "ExcelFstream.h"
//
//////		Input object		////
//
//void ExcelIfstream::inputToPerson(Person& person, vector<string> container, int& curr_pos)
//{
//	int i, count = 0;
//
//
//	for (i = curr_pos, count = 0; count < 4; i++, count++)
//	{
//		switch (count)
//		{
//		case 0:
//
//			person._name = container[i];
//			break;
//
//		case 1:
//
//			string(person._date_of_birth) = container[i];
//			break;
//
//		case 2:
//
//			person._phone_number = container[i];
//			break;
//
//		case 3:
//
//			string(person._address) = container[i];
//			break;
//		}
//	}
//
//
//	curr_pos = i;
//}
//
//void ExcelIfstream::inputToProductInBill(Product product, vector<string> container, int& curr_pos)
//{
//	int i, count = 0;
//	for (i = curr_pos, count = 0; count < 4; i++, count++)
//	{
//		switch (count)
//		{
//		case 0:
//
//			product._product_id = container[i];
//			break;
//
//		case 1:
//
//			product._product_name = container[i];
//			break;
//
//		case 2:
//
//			product._product_price = stod(container[i]);
//			break;
//
//		case 3:
//
//			product._discount = stod(container[i]);
//			break;
//		}
//	}
//	curr_pos = i;
//}
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//void ExcelIfstream::inputToObject(Product& product, vector<string> container)
//{
//	for (int i = 0; i < container.size(); i++)
//	{
//		switch (i)
//		{
//		case 0:
//			product._product_name = container[i];
//			break;
//
//		case 1:
//			product._product_type = container[i];
//			break;
//
//		case 2:
//			product._product_color = container[i];
//			break;
//
//		case 3:
//			product._product_size = container[i];
//			break;
//
//		case 4:
//			product._product_id = container[i];
//			break;
//
//		case 5:
//			product._firm_name = container[i];
//			break;
//
//		case 6:
//			product._discount = stod(container[i]);
//			break;
//
//		case 7:
//			product._product_price = stod(container[i]);
//			break;
//
//		case 8:
//			product._product_cost = stod(container[i]);
//			break;
//
//		case 9:
//			product._stock_in_time.date = Date::parse(container[i]);
//			break;
//
//		case 10:
//			product._stock_in_time.time = MyTime::parse(container[i]);
//			break;
//
//		case 11:
//			product._stock_out_time.date = Date::parse(container[i]);
//			break;
//
//		case 12:
//			product._stock_out_time.time = MyTime::parse(container[i]);
//			break;
//
//		case 13:
//			product._stock_cover_time.date = Date::parse(container[i]);
//			break;
//
//		case 14:
//			product._stock_cover_time.time = MyTime::parse(container[i]);
//			break;
//
//		case 15:
//			product._quantity_out_of_stock = stoi(container[i]);
//			break;
//		}
//	}
//}
//
//void ExcelIfstream::inputToObject(Account& account, vector<string> container)
//{
//	for (int i = 0; i < container.size(); i++)
//	{
//		switch (i)
//		{
//		case 0:
//			account._account_id = container[i];
//			break;
//
//		case 1:
//			inputToPerson(account._customer, container, i);
//			break;
//
//		case 5:
//			account._customer._customer_id = container[i];
//			break;
//
//		case 6:
//			account._membership_level._level = container[i];
//			break;
//
//		case 7:
//			account._membership_level._cumulative_points = stoi(container[i]);
//			break;
//		}
//	}
//}
//
//void ExcelIfstream::inputToObject(Bill& bill, vector<string> container)
//{
//	for (int i = 0; i < container.size(); i++)
//	{
//		switch (i)
//		{
//		case 0:
//
//			bill._bill_id = container[i];
//			break;
//
//		case 1:
//
//			inputToProductInBill(bill._product, container, i);
//			break;
//
//		case 2:
//
//			bill._curr_date = Date::parse(container[i]);
//			break;
//
//		}
//	}
//}
//
//void ExcelIfstream::inputToObject(Security& security, vector<string> container)
//{
//	for (int i = 0; i < container.size(); i++)
//	{
//		switch (i)
//		{
//		case 0:
//			security._staff_id = container[i];
//			break;
//
//		case 1:
//			inputToPerson(security, container, i);
//			break;
//
//		case 5:
//			security._base_salary = stod(container[i]);
//			break;
//		}
//	}
//}
//
//
////void ExcelIfstream::inputToObject(Seller& seller, vector<string> container)
////{
////
////}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//void ExcelIfstream::open(string directory, ios_base::openmode mode)
//{
//	for (int i = 0; i < directory.size(); i++)
//	{
//		if (directory[i] == '/')
//		{
//			directory.insert(i, "/");
//		}
//	}
//	this->_file_in.open(directory, mode | ios::app);
//}
//
//void ExcelIfstream::close()
//{
//	this->_file_in.close();
//}
//
//vector<string> ExcelIfstream::parse(const string& line)
//{
//	auto container = Tokenizer::parse(line, ",");
//	return container;
//}