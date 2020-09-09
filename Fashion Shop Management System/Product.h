#ifndef _PRODUCT_
#define _PRODUCT_


#include <iostream>
#include<sstream>
#include <vector>
#include <ctime>
#include <Date.h>
#include <Clock.h>
#include <MyTime.h>
#include <ExcelFstream.h>

using namespace std;

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

	
	Date _stock_in_time;
	Date _stock_out_time;
	Date _stock_cover_time;

public:

	Product();
	Product(string, string, string, string, string, string, double, double, double, Date, Date, Date);
	string toString();
	void setProductInfo(vector<string>);
	void showProductInfo();

	static void setProductsInfo(vector<Product>&, vector<vector<string>>);
	static void showProductsInfo(vector<Product>);
	static void sort(vector<Product>&, string);
	static Product search_by_ProductId(vector<Product>&, string);
	static void addProduct(vector<Product>&, Product);
	static void deleteProduct(vector<Product>&, Product);
	static void addProductInFile(vector<Product>&, vector<vector<string>>&, Product, ExcelFstream);
	static void deleteProductInFile(vector<Product>&, vector<vector<string>>&, Product, ExcelFstream);

	string getProductName(){ return _product_name; }
	string getProductId() { return _product_id; }
	string getFirmName() { return _firm_name; }
	string getProductType() { return _product_type; }
	string getProductColor() { return _product_color; }
	string getProductSize() { return _product_size; }

	double getProductCost() { return _product_cost; }
	double getProductPrice() { return _product_price; }
	double getDiscount() { return _discount; }

	Date getStockInTime() { return _stock_in_time; }
	Date getStockOutTime() { return _stock_out_time; }
	Date getStockCoverTime() { return _stock_cover_time; }

	int getQuantityOutOfStock() { return _quantity_out_of_stock; }

	////		Friend function		////
	friend class ExcelFstream;
	friend class ExcelOfstream;
	friend class ExcelIfstream;
};



#endif