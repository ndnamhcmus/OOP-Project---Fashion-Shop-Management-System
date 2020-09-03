#include "Client.h"

////		static member		////

string Client::separator = " - ";

string Client::order = "000";

////		Constructor		////

Client::Client(const string& id, const string& full_name, const long int& balance)
{
	_id = id;
	_full_name = full_name;
	_balance = balance;
}

////		Method		////

string Client::id()
{
	return _id;
}

string Client::full_name()
{
	return _full_name;
}

long int Client::balance()
{
	return _balance;
}

void Client::setID()
{
	getline(cin, _id);
}

void Client::setFullName()
{
	getline(cin, _full_name);
}

void Client::setBalance()
{
	cin >> _balance;
}

string Client::toString()
{
	stringstream writer;
	writer << _id << separator << _full_name << separator << _balance;

	return writer.str();
}

Client Client::parse(const string& line)
{
	auto container = Tokenizer::parse(line, separator);
	return Client(container[0], container[1], stoi(container[2]));
}

Client::operator string()
{
	return toString();
}
