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

private:

	template <class T>
	void updateList(vector <T>& list, T element)
	{
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].getID() == element.getID())
			{
				list[i] = element;
				return;
			}
		}
	}

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
		saveStaffList();


		if (_staffs.size())
		{
			for (int i = 0; i < _staffs.size(); i++)
			{
				if (_staffs[i])
				{
					delete _staffs[i];
				}
			}
		}
	}

private:

	void sortProduct();
	void sortAccount();
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

	void showStaffList();
	void showSellerList();
	void showSecurityList();

	void showProductList();

private:

	void Purchase();

	void ProductManagement();

private:

	Account AccountManagement();

private:

	void StaffInfoManagement();
	void SellerInfoManagement();
	void SecurityInfoManagement();
};


#endif