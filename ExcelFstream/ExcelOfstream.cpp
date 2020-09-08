//#include "ExcelFstream.h"
//
//
//////		EXCEL OUT FILE STREAM		////
//
//////		Main write file		///
//
//void ExcelOfstream::writeExcelFile(Product product, const string& file_name)
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
//	////		Lưu tạm vào buffer để kiểm tra		////
//	stringstream buffer;
//
//	buffer << product._product_name << "," << product._product_type << "," << product._product_color << "," << product._product_size << "," << product._product_id << "," << product._firm_name << ",";
//	buffer << to_string(product._discount) << "," << to_string(product._product_price) << "," << to_string(product._product_cost) << ",";
//	buffer << string(product._stock_in_time.date) << "," << product._stock_in_time.time.toString() << "," << string(product._stock_out_time.date) << "," << product._stock_out_time.time.toString() << "," << string(product._stock_cover_time.date) << "," << product._stock_cover_time.time.toString() << ",";
//	buffer << product._quantity_out_of_stock << endl;
//
//
//	////		Save to file		////
//	_file_out << buffer.str();
//}
//
//void ExcelOfstream::writeExcelFile(Account account, const string& file_name)
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
//	stringstream buffer;
//	buffer << account._account_id << ",";
//	inputBuffer(account._customer);
//	inputBuffer(account._membership_level);
//
//
//	_file_out << buffer.str();
//}
//
//
//////		TO DO: Seller đang viết dở		/////
//
////void ExcelOfstream::writeExcelFile(Seller seller, const string& file_name)
////{
////	try
////	{
////		if (!(this->_file_out))
////		{
////			stringstream writer;
////			writer << file_name << " is not open";
////			throw string(writer.str());
////		}
////	}
////	catch (const string& notification)
////	{
////		cout << notification << endl;
////		exit(EXIT_FAILURE);
////	}
////
////
////	writeStaffInfoToExcelFile(seller);
////	_file_out << seller._goods_sale << "," << seller._commission << "," << seller._real_salary << ",";
////	_file_out << endl;
////}
//
//void ExcelOfstream::writeExcelFile(Security security, const string& file_name)
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
//	stringstream buffer;
//	buffer << security._staff_id << ",";
//	inputPersonToBuffer(security);
//	buffer << security._base_salary << ",";
//
//
//	_file_out << buffer.str();
//}
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//////		Input buffer		////
//
//void ExcelOfstream::inputPersonToBuffer(Person person)
//{
//	_buffer << person._name << "," << string(person._date_of_birth) << "," << person._phone_number << "," << string(person._address) << ",";
//}
//
//void ExcelOfstream::inputBuffer(Customer customer)
//{
//	inputPersonToBuffer(customer);
//	_buffer << customer._customer_id << ",";
//}
//
//void ExcelOfstream::inputBuffer(MembershipLevel membership_level)
//{
//	_buffer << membership_level._level << "," << membership_level._cumulative_points << ",";
//}
//
//void ExcelOfstream::writeExcelfile(Bill bill, const string& file_name)
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
//	_buffer << bill._bill_id << ",";
//	_buffer << bill._product._product_id << "," << bill._product._product_name << "," << bill._product._product_price << "," << bill._product._discount << ",";
//	_buffer << string(bill._curr_date) << ",";
//
//
//	_file_out << _buffer.str();
//}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//void ExcelOfstream::open(string directory, ios_base::openmode mode)
//{
//	for (int i = 0; i < directory.size(); i++)
//	{
//		if (directory[i] == '/')
//		{
//			directory.insert(i, "/");
//		}
//	}
//	this->_file_out.open(directory, mode | ios::app);
//}
//
//void ExcelOfstream::close()
//{
//	this->_file_out.close();
//}
