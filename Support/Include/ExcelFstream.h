#ifndef _EXCEL_FSTREAM_
#define _EXCEL_FSTREAM_


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include <Tokenizer.h>

using namespace std;


//class ExcelIfstream
//{
//	
//protected:		////		Protected attributes		////
//
//	ifstream _file_in;
//
//public:
//
//	~ExcelIfstream()
//	{
//		_file_in.close();
//	}
//
//	
//protected:		////		Private method: chỉ dùng trong Input Fstream		////
//
//	void inputToPerson(Person& person, vector <string> container, int& curr_pos);
//
//	void inputToObject(Product& product, vector <string> container);
//
//	void inputToObject(Account& account, vector <string> container);
//
//	void inputToObject(Bill& bill, vector <string> container);		//		method này chưa đúng
//
//	void inputToObject(Security& security, vector <string> container);
//
//	//void inputToObject(Seller& seller, vector <string> container);
//
//	void inputToProductInBill(Product product, vector <string> container, int& curr_pos);
//
//	
//protected:		////		Protected method: có thể dùng ở derived class		////
//
//	/*void readExcelFile(Customer& customer, const string& file_name = "Product.csv");
//
//	void readExcelFile(MembershipLevel& membership);
//
//	void readStaffInfoFromFile(Staff& staff);*/
//
//public:
//
//	void open(string directory, ios_base::openmode mode = ios::in);
//
//	void close();
//
//public:
//
//	template <class T>
//	void readExcelFile(T& object, const string& file_name = "File.csv");
//
//	//void readExcelFile(Account& account, const string& file_name = "Account.csv");
//
//	//void readExcelFile(Bill& bill, const string& file_name = "Bill.csv");
//
//	/*void readExcelFile(Seller& seller, const string& file_name = "Staff.csv");*/
//
//	//void readExcelfile(Security& security, const string& file_name = "Staff.csv");
//
//protected:
//
//	static vector <string> parse(const string& line);
//
//};
//
//class ExcelOfstream
//{
//protected:
//
//	ofstream _file_out;
//
//	stringstream _buffer;
//
//public:
//
//	~ExcelOfstream()
//	{
//		_file_out.close();
//
//
//		_buffer.str("");
//		_buffer.clear();
//	}
//
//protected:		////		Buffer: lưu tạm để input vào object chính		////
//
//	void inputPersonToBuffer(Person person);
//
//	void inputBuffer(Customer customer);
//
//	void inputBuffer(MembershipLevel membership_level);
//
//	
//public:		////		OPEN/CLOSE		////
//	void open(string directory, ios_base::openmode mode = ios::out);
//
//	void close();
//
//public:		////		Main write file		////
//
//	
//	void writeExcelFile(Product product, const string& file_name = "Product.csv");
//
//	void writeExcelFile(Account account, const string& file_name="Account.csv");
//						
//	void writeExcelfile(Bill bill, const string& file_name = "Bill.csv");
//						
//	/*void writeExcelFile(Seller seller, const string& file_name = "Staff.csv");*/
//
//	void writeExcelFile(Security security, const string& file_name = "Staff.csv");
//};

class ExcelFstream
{
private:

	fstream _file;

private:

	stringstream _buffer;

public:

	~ExcelFstream()
	{
		close();
	}

public:

	void open(const string& path, ios_base::openmode mode = ios::in | ios::out);

	void close();

public:

	void readExcelString(vector<vector <string>>& container);

	void writeExcelString(const string& String, const string& needle = " - ");

};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ExcelFstreamException : public exception
{
private:

	string _exception_mess;

public:

	ExcelFstreamException(string exception_mess)
	{
		this->_exception_mess = exception_mess;
	}


	const char* what() const throw()
	{
		return _exception_mess.c_str();
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//template<class T>
//inline void ExcelIfstream::readExcelFile(T& object, const string& file_name)
//{
//	try
//	{
//		if (!(this->_file_in))
//		{
//			stringstream writer;
//			writer << file_name << " is not open";
//			throw ExcelFstreamException(writer.str());
//		}
//	}
//	catch (const exception& mess)
//	{
//		cout << mess.what() << endl;
//		exit(EXIT_FAILURE);
//	}
//
//
//	string buffer;
//	while (getline(_file_in, buffer))
//	{
//		auto container = this->parse(buffer);
//
//
//		inputToObject(object, container);
//	}
//}


#endif // !_EXCEL_FSTREAM_


