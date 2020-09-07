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

	Product();
	Product(string, string, string, string, string, string, double, double, double, TimeOfProduct, TimeOfProduct, TimeOfProduct);
	void addProductInFile(Product);
	void deleteProductInFile(Product);
	void modifyProductInFile(string, string);
	void setInfoProduct(vector<string>);
	void showProductInfo();

	static void setInfoProducts(vector<Product>&, vector<vector<string>>);
	static void sort(vector<Product>&, string);
	static Product search_by_ProductId(vector<Product>&, string);

	string getProductName(){ return _product_name; }
	string getProductId() { return _product_id; }
	string getFirmName() { return _firm_name; }
	string getProductType() { return _product_type; }
	string getProductColor() { return _product_color; }
	string getProductSize() { return _product_size; }

	double getProductCost() { return _product_cost; }
	double getProductPrice() { return _product_price; }
	double getDiscount() { return _discount; }

	TimeOfProduct getStockInTime() { return _stock_in_time; }
	TimeOfProduct getStockOutTime() { return _stock_out_time; }
	TimeOfProduct getStockCoverTime() { return _stock_cover_time; }

	////		Friend function		////
	friend class ExcelFstream;
	friend class ExcelOfstream;
	friend class ExcelIfstream;
};



#endif