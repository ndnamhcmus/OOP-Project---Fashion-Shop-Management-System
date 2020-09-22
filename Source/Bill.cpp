#include "Bill.h"
#include"Tokenizer.h"

Bill::Bill(string id, string level, MembershipLevel membership, Date d, vector<Product> p, string account_id)
{
	_bill_id = id;
	_curr_date = d;
	_level = level;
	_membership = membership;
	_cart.resize(p.size());
	for (int i = 0; i < p.size(); i++)
		_cart[i] = p[i];
	_account_id = account_id;
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
		{
			*this = bills[i];
			return *this;
		}
	throw exception("Not found");
}

void Bill::setBillInfo(vector<string>Tok)
{
	_bill_id = Tok[0];

	vector<string>tokens = Tokenizer::parse(Tok[1], "/");
	
	_curr_date = Date(stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]));

	for (int i = 2; i < Tok.size() - 2; i = i + 2)
	{
		_cart.push_back(Product(Tok[i], "", "", "", "", "", 0.0, stod(Tok[i + 1]), 0.0, Date(), Date(), Date()));
		continue;
	}
	_account_id = Tok[Tok.size() - 1];
}

Bill Bill::getBill()
{
	return *this;
}

string Bill::getLastBillID(vector <Bill> bills)
{
	return bills[bills.size() - 1].getID();
}

string Bill::lastBill_ID_InFile()
{
	vector<Bill> bills;

	Bill::openBillList(bills, "Bill.csv");

	return bills[bills.size() - 1].getID();
}

int Bill::isFoundInList(vector<Bill>& bills, string ID)
{
	for (int i = 0; i < bills.size(); i++)
		if (bills[i].getID() == ID) {
			return i + 1;
		}
	return 0;
}

void Bill::deleteBill(vector<Bill>& bills)
{
	int index;
	if (isFoundInList(bills, _bill_id)) {
		bills.erase(bills.begin() + isFoundInList(bills, _bill_id) - 1);
		throw exception("Deleted successfully");
	}
	else
		throw BillException("Deleted failed");
}

string Bill::getID()
{
	return _bill_id;
}

string Bill::getAccountID()
{
	return _account_id;
}

Date Bill::getDate()
{
	return _curr_date;
}

void Bill::setMembershipLevel(string level)
{
	_level = level;
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
	w << "Total:" << to_string(total) << " - " << _account_id;

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

	//cout << "Name\t\t\tCost\tDiscount\tRate\n";

	cout << "Name:\n";
	for (int i = 0; i < _cart.size(); i++) 
	{
		cout << _cart[i].getProductName() << endl;
	}

	cout << "Cost:\n";
	for (int i = 0; i < _cart.size(); i++)
	{
		cout << _cart[i].getProductPrice() << "$" << endl;
	}

	cout << "Discount\n";
	for (int i = 0; i < _cart.size(); i++)
	{
		buffer << to_string(static_cast<int>(_cart[i].getDiscount() * 100)) << "%";
		cout << buffer.str() << endl;

		buffer.str("");
		buffer.clear();
	}

	cout << "Rate:\n";
	for (int i = 0; i < _cart.size(); i++) {
		
		cout << _cart[i].getProductPrice() * (1 - _cart[i].getDiscount()) << endl;

		total += _cart[i].getProductPrice() * (1 - _cart[i].getDiscount());
	}

	buffer << to_string(static_cast<int>(MembershipLevel::getDiscount(_level) * 100)) << "%";
	total = total * (1 - MembershipLevel::getDiscount(_level));


	cout << "\n--------------------------------\n";
	cout << "Member discounts:\t\t" << buffer.str() << endl;
	cout << "Total:\t\t\t" << total << "$" << endl;
	cout << "\n---***   THANK YOU VISIT AGAIN   ***---\n";
}

void Bill::saveBillList(vector <Bill> bills, string directory)
{
	string buffer;
	ExcelFstream file;
	file.open(directory, ios::out);


	for (int i = 0; i < bills.size(); i++)
	{
		buffer = bills[i].toString();
		file.writeExcelString(buffer);
	}
	file.close();
}

void Bill::openBillList(vector <Bill>& bills, string path)
{
	ExcelFstream file;
	file.open(path, ios::in);

	vector <vector <string>> container;
	file.readExcelString(container);

	for (int i = 0; i < container.size(); i++)
	{
		Bill bill;
		try
		{
			bill.setBillInfo(container[i]);
		}
		catch (const std::exception&)
		{
			throw exception("Something happened while Bill was setting up information");
		}
		bills.push_back(bill);
	}
	file.close();


	if (!(bills.size()))
	{
		throw exception("Bill list is empty");
	}
}
