#include "Product.h"

int Product::_quantity_out_of_stock = 0;

Product::Product(){}

Product::Product(string product_name, string product_id, string firm_name, string product_type, string product_color, string product_size, 
	double product_cost, double product_price, double discount, TimeOfProduct stock_in_time, TimeOfProduct stock_out_time, TimeOfProduct stock_cover_time) {

	_product_name = product_name;
	_product_id = product_id;
	_firm_name = firm_name;
	_product_type = product_type;
	_product_color = product_color;
	_product_size = product_size;
	_product_cost = product_cost;
	_product_price = product_price;
	_discount = discount;
	_stock_in_time = stock_in_time;
	_stock_out_time = stock_out_time;
	_stock_cover_time = stock_cover_time;

}

void Product::addProductInFile(Product) {

}

void Product::deleteProductInFile(Product) {

}

void Product::modifyProductInFile(string, string) {

}

void Product::parse(string) {

}

void Product::showProductInfo() {

}