#ifndef _SHOP_
#define _SHOP_

#include "Person_Customer_Staff_Seller_Security.h"
#include "Product.h"
#include "Account.h"
#include "Bill.h"
#include "Menu.h"


#include <ExcelFstream.h>
#include <string>
#include <sstream>


class Shop
{
private:

	vector <Product> _products;
	vector <Account> _accounts;
	vector <Staff*> _staffs;

private:

	void sortProduct(string sort_by);
	void sortAccount(string sort_by);
	void sortStaff(string sort_by);

private:

	void openProductList();
	void openAccountList();
	void openStaffList();


	void saveProductList();
	void saveAccountList();
	void saveStaffList();

public:

	void Start();

private:

	void showProductList();
	void ProductManagement();

private:

	void Trading();


	void StaffInfoManagement();
	void SellerInfo();
	void SecurityInfo();
};


#endif