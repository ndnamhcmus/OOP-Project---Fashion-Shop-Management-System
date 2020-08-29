#ifndef _CLIENT_
#define _CLIENT_


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <Tokenizer.h>
#include <FakeName.h>
#include <Random.h>
#include <exception>


using namespace std;

class Client
{
public:

	static string separator;
	static string order;

private:

	string _id;
	string _full_name;
	long int _balance;

public:
	////		Set up and get method		////
	string id();
	string full_name();
	long int balance();


	void setID();
	void setFullName();
	void setBalance();

public:

	Client(const string& id = "", const string& full_name = "", const long int& balance = 0);

	string toString();

	static Client parse(const string& line);

public:
	template <class T>
	static void readFile(vector <T>& clients, const string& path = "path.txt", ios_base::openmode mode = ios::in);

	template <class T>
	static void writeFile(vector <T> clients, const string& path = "path.txt", ios_base::openmode mode = ios::out);

public:
	////		Operator			////
	operator string();
};

class FileException : public exception
{
private:

	string _exception_mess;

public:
	FileException(const string& exception_mess)
	{
		this->_exception_mess = exception_mess;
	}


	const char* what() const throw()
	{
		return _exception_mess.c_str();
	}
};


#include "ReadWriteFile.cpp"
#endif // !_CLIENT_