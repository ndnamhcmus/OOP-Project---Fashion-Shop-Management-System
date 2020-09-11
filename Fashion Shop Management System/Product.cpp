#include "Product.h"

int Product::_quantity_out_of_stock = 0;

Product::Product(){}

Product::Product(string product_name, string product_id, string firm_name, string product_type, string product_color, string product_size, 
	double product_cost, double product_price, double discount, Date stock_in_time, Date stock_out_time, Date stock_cover_time) {

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

string Product::toString() {
	stringstream writer;
	writer << _product_name << " - " << _product_id << " - " << _firm_name << " - " << _product_type << " - " << _product_color << " - "
		<< _product_size << " - " << _product_cost << " - " << _product_price << " - " << _discount << " - " << _stock_in_time.toString()
		<< " - " << _stock_out_time.toString() << " - " << _stock_cover_time.toString();
	return writer.str();
}

Product Product::parse(string line) {
	auto Tok = Tokenizer::parse(line, ",");
	Product prd;
	prd.setProductInfo(Tok);
	return prd;
}

void Product::setProductInfo(vector<string> Tok) {

	this->_product_name = Tok[0];
	this->_product_id = Tok[1];
	this->_firm_name = Tok[2];
	this->_product_type = Tok[3];
	this->_product_color = Tok[4];
	this->_product_size = Tok[5];
	this->_product_cost = stod(Tok[6]);
	this->_product_price = stod(Tok[7]);
	this->_discount = stod(Tok[8]);
	this->_stock_in_time.parse(Tok[9]);
	this->_stock_out_time.parse(Tok[10]);
	this->_stock_cover_time.parse(Tok[11]);

}

void Product::showProductInfo() {

}

void Product::setProductsInfo(vector<Product>& products) {

	vector<vector<string>> container;
	ExcelFstream file;
	file.open("Product.csv", ios::app);
	file.readExcelString(container);
	file.close();

	for (int i = 0; i < container.size(); i++) {
		Product prd;
		prd.setProductInfo(container[i]);
		products.push_back(prd);
	}

}

void Product::showProductsInfo(vector<Product> products) {

}

void Product::addProduct(vector<Product>& products, Product prd) {
	products.push_back(prd);
}

void Product::deleteProduct(vector<Product>& products, Product prd) {
	int index = -1;
	for (int i = 0; i < products.size(); i++) {
		if (products[i].getProductId() == prd.getProductId()) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		cout << "Product not found" << endl;
	}
	else
		products.erase(products.begin() + index);
}

void Product::addProductInFile(vector<Product>& products, Product prd) {
	vector<vector<string>> container;
	ExcelFstream file;
	Product::addProduct(products, prd);
	file.open("Product.csv", ios::app);
	file.writeExcelString(prd.toString());
	file.close();
}

void Product::deleteProductInFile(vector<Product>& products, Product prd) {
	vector<vector<string>> container;
	ExcelFstream file;
	Product::deleteProduct(products, prd);
	file.open("Product.csv");
	for (auto& products : products) {
		file.writeExcelString(products.toString());
	}
	file.close();
}

Product Product::getProduct(vector<Product>& products, string id) {
	Product prd;
	prd = Product::search_by_ProductId(products, id);
	Product::deleteProduct(products, prd);
	return prd;
}

void Product::sort(vector<Product>& products, string sort_by) {

 
	if (sort_by == "_product_id") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getProductId() > products[j].getProductId())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_firm_name") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getFirmName() > products[j].getFirmName())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_type") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getProductType() > products[j].getProductType())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_color") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getProductColor() > products[j].getProductColor())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_size") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getProductSize() > products[j].getProductSize())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_cost") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getProductCost() > products[j].getProductCost())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_price") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getProductPrice() > products[j].getProductPrice())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_discount") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getDiscount() > products[j].getDiscount())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_stock_in_time") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getStockInTime() > products[j].getStockInTime())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_stock_out_time") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getStockOutTime() > products[j].getStockOutTime())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_stock_cover_time") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getStockCoverTime() > products[j].getStockCoverTime())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_quantity_out_of_stock") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getQuantityOutOfStock() > products[j].getQuantityOutOfStock())
					swap(products[i], products[j]);
		return;
	}
}

Product Product::search_by_ProductId(vector<Product>& products, string search_by) {

	for (int i = 0; i < products.size(); i++)
		if (products[i].getProductId() == search_by)
			return products[i];

}