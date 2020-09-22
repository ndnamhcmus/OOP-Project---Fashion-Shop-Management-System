#include "Product.h"

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
		<< _product_size << " - " << to_string(_product_cost) << " - " << to_string(_product_price) << " - " << to_string(_discount) << " - " << _stock_in_time.toString();
	if (!_stock_out_time.getDay() && !_stock_out_time.getMonth() && !_stock_out_time.getYear()) {
		writer << " - " << "Products are not out of stock";
	}
	else
		writer << " - " << _stock_out_time.toString();
	return writer.str();
}

string Product::show() {
	stringstream writer;
	writer << _product_name << " - " << _product_id << " - " << _firm_name << " - " << _product_type << " - " << _product_color << " - "
		<< _product_size << " - " << to_string(_product_price) << " - " << to_string(_discount) << " - " << _stock_in_time.toString();
	if (!_stock_out_time.getDay() && !_stock_out_time.getMonth() && _stock_out_time.getYear()) {
		writer << " - " << "Products are not out of stock";
	}
	else
		writer << " - " << _stock_out_time.toString();
	return writer.str();
}

void Product::set() { 
	cout << "Product name - Product ID - Firm name - Product type - Product color - Product size - Product cost - Product price - Discount - Stock in time - Stock out time (type: 00/00/01)" << endl;
	cout << "Please enter the information in the form above" << endl;
	string line;
	getline(cin, line);


	if (line == "cancel")
	{
		throw ProductException("Cancel!!!");
	}

	auto Tok = Tokenizer::parse(line, " - ");
	if (Tok.size() != 11)
	{
		throw exception("Invalid, try again!!!");
	}
	this->setProductInfo(Tok);
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

	auto test_case = Tokenizer::parse(Tok[9], "/");
	if (test_case.size() != 3)
	{
		throw exception("Invalid, try again!!!");
	}
	test_case.clear();
	this->_stock_in_time = this->_stock_in_time.parse(Tok[9]);

	test_case = Tokenizer::parse(Tok[9], "/");
	if (test_case.size() != 3)
	{
		throw exception("Invalid, try again!!!");
	}
	test_case.clear();
	this->_stock_out_time = this->_stock_out_time.parse(Tok[10]);
}
 
void Product::showProductInfoForStaff()
{
	cout << toString();
}

void Product::showProductInfo() {
	cout << this->show();
}

void Product::setStockOutTime() {
	this->_stock_out_time = Date();
}

void Product::openProductList(vector<Product>& products, string directory) {

	vector<vector<string>> container;
	ExcelFstream file;
	file.open(directory, ios::in);
	file.readExcelString(container);
	file.close();

	for (int i = 0; i < container.size(); i++) {
		Product prd;
		try
		{
			prd.setProductInfo(container[i]);
		}
		catch (const std::exception& mess)
		{
			throw exception("Something happened while Product was setting up infomation");
		}
		products.push_back(prd);
	}

	if (!(products.size()))
	{
		throw ProductException("Product list is empty");
	}
}

void Product::showProductsInfo(vector<Product> products) {
	cout << "Product name - Product ID - Firm name - Product type - Product color - Product size - Product price - Discount - Stock in time - Stock out time" << endl;
	for (int i = 0; i < products.size(); i++) {
		cout << endl << i + 1 << ": ";
		products[i].showProductInfo();
		cout << endl;
	}
}

void Product::addProduct(vector<Product>& products)
{
	products.push_back(*this);
}

//void Product::addProduct(vector<Product>& products, Product prd) {
//	products.push_back(prd);
//}

void Product::deleteProduct(vector<Product>& products) {
	int index;
	if (Product::isValidInList(products, _product_id, index)) {
		products.erase(products.begin() + index);
	}
	else
		throw exception("Product not found");
}

void Product::addProductInFile(vector<Product>& products, string directory) {
	vector<vector<string>> container;
	ExcelFstream file;
	this->addProduct(products);
	file.open(directory, ios::out | ios::app);
	file.writeExcelString(toString());
	file.close();
}

void Product::deleteProductInFile(vector<Product>& products, string directory) {
	vector<vector<string>> container;
	ExcelFstream file;
	this->deleteProduct(products);
	file.open(directory, ios::out);
	for (auto& products : products) {
		file.writeExcelString(products.toString());
	}
	file.close();
}

void Product::buyProduct(vector<Product>& products, vector<Product>& productssold) {
	this->setStockOutTime();
	this->addProduct(productssold);
	this->deleteProduct(products);
}

void Product::sort(vector<Product>& products, string sort_by) {

	if (sort_by == "name") {
		for (int i = 0; i < products.size() - 1; i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductName() > products[j].getProductName())
					swap(products[i], products[j]);
		return;
	}
 
	if (sort_by == "id") {
		for (int i = 0; i < products.size() - 1; i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductId() > products[j].getProductId())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "firm name") {
		for (int i = 0; i < products.size() - 1; i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getFirmName() > products[j].getFirmName())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "type") {
		for (int i = 0; i < products.size() - 1; i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductType() > products[j].getProductType())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "color") {
		for (int i = 0; i < products.size() - 1; i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductColor() > products[j].getProductColor())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "size") {
		for (int i = 0; i < products.size() - 1; i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductSize() > products[j].getProductSize())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "cost") {
		for (int i = 0; i < products.size() - 1; i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductCost() > products[j].getProductCost())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "price") {
		for (int i = 0; i < products.size() - 1; i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductPrice() > products[j].getProductPrice())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "discount") {
		for (int i = 0; i < products.size() - 1; i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getDiscount() > products[j].getDiscount())
					swap(products[i], products[j]);
		return;
	}
}



bool Product::isValidInList(vector<Product> products, string search_by, int &index) {
	for (int i = 0; i < products.size(); i++)
		if (products[i].getProductId() == search_by) {
			index = i;
			return true;
		}
	throw exception("Product not found");
	return false;
}

Product Product::search_by_ProductId(vector<Product> products, int index) {
	*this = products[index];
	return *this;
}

void Product::saveProductList(vector<Product> products, string directory) {
	ExcelFstream file;
	file.open(directory, ios::out);
	for (auto& products : products) {
		file.writeExcelString(products.toString());
	}
	file.close();
}

vector<string> Product::getBestSelling(string directory) {
	vector<Product> productssold;
	Product::openProductList(productssold, directory);
	vector<string> productname;
	vector<string> bestselling;

	for (int i = 0; i < productssold.size(); i++)
		productname.push_back(productssold[i].getProductName());

	for (int i = 0; i < productname.size(); i++)
		for (int j = i + 1; j < productname.size(); j++)
			if (productname[i] > productname[j])
				swap(productname[i], productname[j]);

	int max = 0;
	int count = 1;
	
	for (int i = 0; i < productname.size() - 1; i++) {
		if (productname[i] == productname[i + 1]) {
			count++;
			if (i == productname.size() - 2 && count == max) {
				bestselling.push_back(productname[i]);
			}

			if (i == productname.size() - 2 && count > max) {
				while (bestselling.size() > 0)
					bestselling.erase(bestselling.begin());
				bestselling.push_back(productname[i]);
			}
		}
		else {
			if (count == max) {
				bestselling.push_back(productname[i]);
			}
			if (count > max) {
				max = count;
				while (bestselling.size() > 0)
					bestselling.erase(bestselling.begin());
				bestselling.push_back(productname[i]);
			}
			count = 1;
		}
	}
		
	return bestselling;
}

void Product::showBestSellingProduct() {
	vector<string> bestselling = Product::getBestSelling();
	cout << "The best selling products are:" << endl;
	for (int i = 0; i < bestselling.size(); i++)
		cout << i + 1 << ": " << bestselling[i] << endl;
}
