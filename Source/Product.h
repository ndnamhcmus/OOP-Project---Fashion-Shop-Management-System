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


	double _product_cost;
	double _product_price;
	double _discount;

	
	Date _stock_in_time;
	Date _stock_out_time;
	Date _stock_cover_time;

public:

	Product();
	Product(string product_name, string product_id, string firm_name, string product_type, string product_color, string product_size,
		double product_cost, double product_price, double discount, Date stock_in_time, Date stock_out_time, Date stock_cover_time);

private:

	void setProductInfo(vector<string> Tok);
	string toString();
	string show();

public:
	
	void set();
	void setStockOutTime();

public:

	static void openProductList(vector<Product>& products, string directory = "../Fashion Shop Management System/Database/Product.csv");
	static void saveProductList(vector<Product> products, string directory = "../Fashion Shop Management System/Database/Product.csv");

	void addProductInFile(vector<Product>& products, string directory = "../Fashion Shop Management System/Database/Product.csv");
	void deleteProductInFile(vector<Product>& products, string directory = "../Fashion Shop Management System/Database/Product.csv");

	static vector<string> getBestSelling(string directory = "../Fashion Shop Management System/Database/Product Sold.csv");
	static void showBestSellingProduct();

	void showProductInfoForStaff();
	void showProductInfo();
	static void showProductsInfo(vector<Product> products);
	static void sort(vector<Product>& products, string sort_by);

	void addProduct(vector<Product>& products);
	//static void addProduct(vector<Product>& products, Product prd);
	void deleteProduct(vector<Product>& products);
	static bool isValidInList(vector<Product> products, string search_by, int& index);

	void buyProduct(vector<Product>& products, vector<Product>& productssold);
	Product search_by_ProductId(vector<Product> products, int index);

public:

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

	////		Friend function		////
	friend class ExcelFstream;
	friend class ExcelOfstream;
	friend class ExcelIfstream;
};


class ProductException : public exception
{
private:

	string _mess;

public:
	ProductException(const string& mess)
	{
		_mess = mess;
	}

	const char* what() const throw()
	{
		return _mess.c_str();
	}

};



#endif