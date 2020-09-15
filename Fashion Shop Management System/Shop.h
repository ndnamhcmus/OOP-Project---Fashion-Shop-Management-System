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
private:	//		List		//

	vector <Product> _products;
	vector <Bill> _bills;
	vector <Account> _accounts;
	vector <Staff*> _staffs;

public:		//		Constructor		//

	Shop()
	{
		openProductList();
		openBillList();
		openAccountList();
		openStaffList();
	}
	
	~Shop()
	{
		saveProductList();
		saveBillList();
		saveAccountList();
	}

private:

	void sortProduct(string sort_by);
	void sortAccount(string sort_by);
	void sortStaff(string sort_by);

private:

	void openProductList();
	void openBillList();
	void openAccountList();
	void openStaffList();


	void saveProductList();
	void saveBillList();
	void saveAccountList();
	void saveStaffList();

public:

	void Start();

private:

	void showProductList();

private:

	void Purchase();

	Account AccountManagement();

private:

	void ProductManagement();

private:

	void StaffInfoManagement();
	void SellerInfo();
	void SecurityInfo();
};


#endif