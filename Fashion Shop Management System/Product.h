#ifndef _PRODUCT_
#define _PRODUCT_


#include <iostream>
#include <vector>
#include <ctime>
#include <Date.h>
#include <Clock.h>
#include <MyTime.h>

using namespace std;

struct TimeOfProduct
{
	Date date;
	MyTime time;
};

class Product
{
private:

	string _product_name;
	string _product_id;
	string _firm_name;
	string _product_type;
	string _product_color;
	string _product_size;

	static int _quantity_out_of_stock;

	double _product_cost;
	double _product_price;
	double _discount;

	
	TimeOfProduct _stock_in_time;
	TimeOfProduct _stock_out_time;
	TimeOfProduct _stock_cover_time;

public:





	friend class ExcelFstream;
};



#endif