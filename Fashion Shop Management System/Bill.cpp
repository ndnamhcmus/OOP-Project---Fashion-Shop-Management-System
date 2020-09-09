#include "Bill.h"

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

	return Bill();
}

void Bill::setBillInfo()
{


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

	return w.str();
}

void Bill::showBillInfo()
{
	cout << this->toString();

}

Bill Bill::saveBillToFile()
{


	return Bill();
}
