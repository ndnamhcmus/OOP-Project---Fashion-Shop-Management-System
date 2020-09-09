#include "Bill.h"
#include"Tokenizer.h"

Bill::Bill(string id, Date d, vector<Product> p)
{
	_bill_id = id;
	_curr_date = d;
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
	this->_bill_id = Tok[0];

	vector<string>tokens = Tokenizer::parse(Tok[1], "/");
	this->_curr_date = Date(stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]));

}

Bill Bill::getBill()
{
	return *this;
}

string Bill::lastBill_ID_InFile()
{

	return string();
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
	long total = 0;

	w << _bill_id << "-" << _curr_date.toString() << "\n";
	for (int i = 0; i < _cart.size(); i++) {
		w << _cart[i].getProductName() << "-" 
		  << _cart[i].getProductPrice() * (1 - _cart[i].getDiscount()) << "\n";

		total += _cart[i].getProductPrice();
	}
	w << "Total:" << total << "\n";

	return w.str();
}

void Bill::showBillInfo()
{
	cout << Bill::toString();
}

void Bill::saveBillToFile()
{



}
