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
		<< _product_size << " - " << to_string(_product_price) << " - " << to_string(_discount) << " - " << _stock_in_time.toString(); 
	if (!_stock_out_time.getDay() && !_stock_out_time.getMonth() && !_stock_out_time.getYear()) {
		writer << " - " << "Products are not out of stock" << endl;
	}
	else
		writer << " - " << _stock_out_time.toString() << endl;
	return writer.str();
}

string Product::set() { 
	cout << "Product's name - Product's ID - Brand name - Product type - Product color - Product size - Product cost - Product price - Discount - Stock in time - Stock out time" << endl;
	cout << "Please enter the information in the form above" << endl;
	string line;
	getline(cin, line);

	if (line == "cancel")
	{
		cout << "Cancel!!!\n";
		return line;
	}

	auto Tok = Tokenizer::parse(line, " - ");
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
	this->_stock_in_time.parse(Tok[9]);
	this->_stock_out_time.parse(Tok[10]);

}
 
void Product::showProductInfo() {
	cout << this->toString() << endl;
}

void Product::setStockOutTime(Date date) {
	_stock_cover_time = date;
}

void Product::setProductsInfo(vector<Product>& products, string FileName) {

	vector<vector<string>> container;
	ExcelFstream file;
	file.open(FileName, ios::in);
	file.readExcelString(container);
	file.close();

	for (int i = 0; i < container.size(); i++) {
		Product prd;
		prd.setProductInfo(container[i]);
		products.push_back(prd);
	}

}

void Product::showProductsInfo(vector<Product> products) {
	cout << "Product's name - Product's ID - Brand name - Product type - Product color - Product size - Product cost - Product price - Discount - Stock in time- Stock out time" << endl;
	for (int i = 0; i < products.size(); i++) {
		cout << i + 1 << ": ";
		products[i].showProductInfo();
	}
}

void Product::addProduct(vector<Product>& products, Product prd) {
	products.push_back(prd);
	cout << "Product has been added successfully" << endl; 
}

void Product::deleteProduct(vector<Product>& products, Product prd) {
	int index;
	if (Product::isValidInList(products, prd.getProductId(), index)) {
		products.erase(products.begin() + index);
		cout << "Product deleted successfully" << endl;
	}
	else
		cout << "Product not found" << endl;
}

void Product::addProductInFile(vector<Product>& products, Product prd, string FileName) {
	vector<vector<string>> container;
	ExcelFstream file;
	Product::addProduct(products, prd);
	file.open(FileName, ios::out | ios::app);
	file.writeExcelString(prd.toString());
	file.close();
}

void Product::deleteProductInFile(vector<Product>& products, Product prd, string FileName) {
	vector<vector<string>> container;
	ExcelFstream file;
	Product::deleteProduct(products, prd);
	file.open(FileName, ios::out);
	for (auto& products : products) {
		file.writeExcelString(products.toString());
	}
	file.close();
}

void Product::buyProduct(vector<Product>& products, vector<Product>& productssold, Product prd) {
	Product::addProduct(productssold, prd);
	Product::deleteProduct(products, prd);
}

void Product::sort(vector<Product>& products, string sort_by) {

	if (sort_by == "_product_name") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductName() > products[j].getProductName())
					swap(products[i], products[j]);
		return;
	}
 
	if (sort_by == "_product_id") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductId() > products[j].getProductId())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_firm_name") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getFirmName() > products[j].getFirmName())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_type") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductType() > products[j].getProductType())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_color") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductColor() > products[j].getProductColor())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_size") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductSize() > products[j].getProductSize())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_cost") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductCost() > products[j].getProductCost())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_price") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size(); j++)
				if (products[i].getProductPrice() > products[j].getProductPrice())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_discount") {
		for (int i = 0; i < products.size(); i++)
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
	return false;
}

Product Product::search_by_ProductId(vector<Product> products, int index) {
	return products[index];
}

void Product::savetoFile(vector<Product> products, string FileName) {
	ExcelFstream file;
	file.open(FileName, ios::out);
	for (auto& products : products) {
		file.writeExcelString(products.toString());
	}
	file.close();
}

vector<string> Product::getBestSelling(string FileName) {
	vector<Product> productssold;
	Product::setProductsInfo(productssold, FileName);
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
				for (int j = 0; j < bestselling.size(); j++)
					bestselling.erase(bestselling.begin() + j);
				bestselling.push_back(productname[i]);
			}
		}
		else {
			if (count == max) {
				bestselling.push_back(productname[i]);
			}
			if (count > max) {
				max = count;
				for (int j = 0; j < bestselling.size(); j++)
					bestselling.erase(bestselling.begin() + j);
				bestselling.push_back(productname[i]);
			}
			count = 1;
		}
	}
		
	return bestselling;
}

//int main() {
//	vector<Product> products;
//	vector<Product> productssold;
//
//	Product::setProductsInfo(products, "Product.csv");
//	Product::setProductsInfo(productssold, "Product sold.csv");
//	
//	////////////////////////// Buy a product ///////////////////////
//	Product prd;
//	string id;
//	int index;
//	if (Product::isValidInList(products, id, index)) {
//		prd = Product::search_by_ProductId(products, index);
//		Product::buyProduct(products, productssold, prd);
//		cout << "Product has been purchased" << endl;
//	}
//	else
//		cout << "The product is out of stock" << endl;
//	/////////////////////////////////////////////////////////////////
//
//	////////////////////////// Add a product ///////////////////////
//	Product prd1;
//	prd1.set();
//	Product::addProduct(products, prd1);
//	/////////////////////////////////////////////////////////////////
//
//
//
//
//}