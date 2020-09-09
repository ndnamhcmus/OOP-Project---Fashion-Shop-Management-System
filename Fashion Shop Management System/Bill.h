#ifndef _BILL_
#define _BILL_


#include <iostream>
#include <string>
#include <Date.h>
#include <Time.h>
#include "Product.h"


class Bill
{
private:

	string _bill_id;
	Date _curr_date;
	vector<Product> _products;

public:


	void sort(vector <Bill> bills, string sort_by);

	Bill search(vector <Bill> bills, string search_by);

	void setBillInfo();

	Bill getBill();

	string lastBill_ID_InFile();

	string getID();

	Date getDate();

	string toString();

	void showBillInfo();

	Bill saveBillToFile();




	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;
};


#endif // !_BILL_