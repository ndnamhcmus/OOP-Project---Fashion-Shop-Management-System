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
	//Product _product;

public:
	Bill();
	~Bill();


};


#endif // !_BILL_