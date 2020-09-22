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
	vector <Product> _products_sold;
	vector <Bill> _bills;
	vector <Account> _accounts;
	static vector <Staff*> _staffs;

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


		releaseStaffPtr();
	}

private:

	void updateList(vector <Staff*>& list, Staff* element)
	{
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i]->getStaffID() == element->getStaffID())
			{
				list[i] = element;
				return;
			}
		}
	}

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



	///		Add new element		///
	template <class T>
	void addToList(vector <T>& list, T element)
	{
		list.push_back(element);
	}


	///		Release Pointer		///
	void releaseStaffPtr()
	{
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

	void sortProductList(vector <Product> products, string sort_by = "id");
	void sortBillList(string sort_by = "id");
	void sortAccountList(string sort_by ="id");
	void sortStaffList(string sort_by = "id", vector <Staff*> staffs = _staffs);

private:

	void openProductList();
	void openBillList();
	void openAccountList();
	void openStaffList();


	void saveProductList();
	void saveBillList();
	void saveAccountList();
	void saveStaffList();

private:

	void showStaffList();
	void showSellerList();
	void showSecurityList();

	void showProductList();
	void showPurchaseHistory();
	void showProductListForStaff();

	void showBillList();

private:

	void bestSelling();

	void Purchase();

private:

	Account AccountManagement();

	void ProductManagement();

private:

	void StaffInfoManagement();
	void SellerInfoManagement();
	void SecurityInfoManagement();

public:

	void Start();
};


#endif