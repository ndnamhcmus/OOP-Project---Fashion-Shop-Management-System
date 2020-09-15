#include "Bill.h"
#include"Tokenizer.h"

Bill::Bill(string id, string level, Date d, vector<Product> p)
{
	_bill_id = id;
	_curr_date = d;
	_level = level;
	_cart.resize(p.size());
	for (int i = 0; i < p.size(); i++)
		_cart[i] = p[i];
}

void Bill::sort(vector<Bill> bills, string sort_by)
{

	if (sort_by == "id") {
		for (int i = 0; i < bills.size() - 1; i++)
			for (int j = i + 1; j < bills.size(); j++)
				if (stoi(bills[i]._bill_id) > stoi(bills[j]._bill_id))
					swap(bills[i], bills[j]);
		return;
	}

}

Bill Bill::search(vector<Bill> bills, string search_by)
{
	for (int i = 0; i < bills.size(); i++)
		if (bills[i]._bill_id == search_by)
			return bills[i];
	return bills[0];
}

void Bill::setBillInfo(vector<string>Tok)
{
	_bill_id = Tok[0];

	vector<string>tokens = Tokenizer::parse(Tok[1], "/");
	
	_curr_date = Date(stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]));


	for (int i = 2; i < Tok.size() - 1; i = i + 2)
	{
		_cart.push_back(Product(Tok[i], "", "", "", "", "", 0.0, stod(Tok[i + 1]), 0.0, Date(), Date(), Date()));
		continue;
	}
}

Bill Bill::getBill()
{
	return *this;
}

string Bill::lastBill_ID_InFile()
{
	vector<Bill> bills;

	Bill::openBillFile(bills, "Bill.csv");

	return bills[bills.size() - 1].getID();
}

string Bill::getID()
{
	return _bill_id;
}

Date Bill::getDate()
{
	return _curr_date;
}

string Bill::toString()
{
	stringstream w;

	double total = 0;


	w << _bill_id << " - " << _curr_date.toString() << " - ";
	for (int i = 0; i < _cart.size(); i++) {
		w << _cart[i].getProductName() << " - " 
		  << to_string(_cart[i].getProductPrice() * (1 - _cart[i].getDiscount())) << " - ";

		total += _cart[i].getProductPrice() * (1 - _cart[i].getDiscount());
	}


	total = total * (1 - MembershipLevel::getDiscount(_level));
	w << "Total:" << to_string(total) << " - ";

	return w.str();
}

void Bill::showBillInfo()
{
	stringstream buffer;
	double total = 0;


	cout << "---SHOP---" << endl;

	cout << "Address: 19CLC6 HCMUS  \n";

	cout << "Phone: 0123456789\n\n";

	cout << "--------------------------------\n";

	cout << "Bill No: " << _bill_id << "\t Date: " << _curr_date.toString() << endl;

	cout << "--------------------------------\n";

	cout << "Name\t\t\tCost\tDiscount\tRate\n";

	for (int i = 0; i < _cart.size(); i++) {
		buffer << to_string(static_cast<int>(_cart[i].getDiscount() * 100)) << "%";
		cout << _cart[i].getProductName() << "\t\t\t" << _cart[i].getProductPrice() << "\t" << buffer.str() << "\t\t" << _cart[i].getProductPrice() * (1 - _cart[i].getDiscount());
		buffer.str("");
		buffer.clear();


		total += _cart[i].getProductPrice() * (1 - _cart[i].getDiscount());
	}

	buffer << to_string(static_cast<int>(MembershipLevel::getDiscount(_level) * 100)) << "%";

	total = total * (1 - MembershipLevel::getDiscount(_level));
	cout << "\n--------------------------------\n";
	cout << "Member discounts:\t\t" << buffer.str() << endl;
	cout << "Total:\t\t\t" << total << endl;
	cout << "\n---***   THANK YOU VISIT AGAIN   ***---\n";


	buffer.str("");
	buffer.clear();
}

void Bill::saveBillToFile(vector <Bill> bills)
{
	string buffer;
	ExcelFstream file;
	file.open("Bill.csv", ios::out);


	for (int i = 0; i < bills.size(); i++)
	{
		buffer = bills[i].toString();
		file.writeExcelString(buffer);
	}
	file.close();
}

void Bill::openBillFile(vector <Bill>& bills, string path)
{
	ExcelFstream file;
	file.open(path, ios::in);

	vector <vector <string>> container;
	file.readExcelString(container);

	for (int i = 0; i < container.size(); i++)
	{
		Bill bill;
		bill.setBillInfo(container[i]);
		bills.push_back(bill);
	}
	file.close();
}
