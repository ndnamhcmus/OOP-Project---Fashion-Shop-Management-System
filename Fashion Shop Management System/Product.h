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
	string toString();
	void parse(string line);
	void setProductInfo(vector<string> Tok);
	void showProductInfo();

	static void setProductsInfo(vector<Product>& products, string FileName);
	static void showProductsInfo(vector<Product> products);
	static void addProduct(vector<Product>& products, Product prd);
	static void deleteProduct(vector<Product>& products, Product prd);
	static void addProductInFile(vector<Product>& products, Product prd, string FileName);
	static void deleteProductInFile(vector<Product>& products, Product prd, string FileName);
	static void buyProduct(vector<Product>& products, vector<Product>& productssold, Product prd);
	static void sort(vector<Product>& products, string sort_by);
	static bool isValidInList(vector<Product>& products, string search_by, int& index);
	static Product search_by_ProductId(vector<Product>& products, int index);
	

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

	////		Friend function		////
	friend class ExcelFstream;
	friend class ExcelOfstream;
	friend class ExcelIfstream;
};



#endif