#include "Shop.h"
#include <algorithm>


/// <summary>
/// Load list
/// </summary>

void Shop::openProductList()
{
	try
	{
		Product::openProductList(_products);
		Product::openProductList(_products_sold, "../Fashion Shop Management System/Data Base/Product Sold.csv");
	}
	catch (const std::exception& mess)
	{
		Menu::gotoxy(55 - strlen(mess.what()) / 2, 0);
		cout << mess.what() << endl;
		system("pause");
		system("cls");
	}
}

void Shop::openBillList()
{
	try
	{
		Bill::openBillList(_bills);
	}
	catch (const std::exception& mess)
	{
		Menu::gotoxy(55 - strlen(mess.what()) / 2, 0);
		cout << mess.what() << endl;
		system("pause");
		system("cls");
	}
	
}

void Shop::openAccountList()
{
	
	try
	{
		Account::openAccountList(_accounts);
	}
	catch (const std::exception& mess)
	{
		Menu::gotoxy(55 - strlen(mess.what()) / 2, 0);
		cout << mess.what() << endl;
		system("pause");
		system("cls");
	}
}

void Shop::openStaffList()
{
	try
	{
		Staff::openStaffList(_staffs);
	}
	catch (const std::exception& mess)
	{
		Menu::gotoxy(55 - strlen(mess.what()) / 2, 0);
		cout << mess.what() << endl;
		system("pause");
		system("cls");
	}
	
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// <summary>
///		Save	///
/// </summary>

void Shop::saveProductList()
{
	if (_products.size())
	{
		sortProductList(_products);
		Product::saveProductList(_products);
	}
	

	if (_products_sold.size())
	{
		sortProductList(_products_sold);
		Product::saveProductList(_products_sold, "../Fashion Shop Management System/Data Base/Product Sold.csv");
	}
}

void Shop::saveBillList()
{
	if (_bills.size())
	{
		sortBillList();
		Bill::saveBillList(_bills);
	}
}

void Shop::saveAccountList()
{
	if (_accounts.size())
	{
		sortAccountList();
		Account::saveAccountList(_accounts);
	}
}

void Shop::saveStaffList()
{
	if (_staffs.size())
	{
		sortStaffList();
		Staff::saveStaffList(_staffs);
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// <summary>
///		Sort	///
/// </summary>
/// <param name="sort_by"></param>

void Shop::sortProductList(vector <Product> products, string sort_by)
{
	Product::sort(products, sort_by);
}

void Shop::sortBillList(string sort_by)
{
	Bill::sort(_bills, sort_by);
}

void Shop::sortAccountList(string sort_by)
{
	Account::sort(_accounts, sort_by);
}

void Shop::sortStaffList(string sort_by)
{
	Staff::sort(_staffs, sort_by);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// <summary>
///		Show	///
/// </summary>

void Shop::showProductList()
{
	cout << "Name\tID\tFirm Name\tType\tColor\tSize\tPrice\tDiscount\n";


	string sort_by;
	cout << "Sort by: ";
	getline(cin, sort_by);
	transform(sort_by.begin(), sort_by.end(), sort_by.begin(), ::tolower);	//	chuyển về chữ thường


	Product::sort(_products, sort_by);
	cout << "PRODUCT LIST\n";
	Product::showProductsInfo(_products);
}

void Shop::showProductListForStaff()
{
	cout << "Sort by: Name\tID\tFirm Name\tType\tColor\tSize\tCost\tPrice\tDiscount\n";


	string sort_by;
	cout << "Choose: ";
	getline(cin, sort_by);
	transform(sort_by.begin(), sort_by.end(), sort_by.begin(), ::tolower);	//	chuyển về chữ thường


	Product::sort(_products, sort_by);
	cout << "PRODUCT LIST\n";
	cout << "Product name - Product ID - Firm name - Product type - Product color - Product size - Product cost - Product price - Discount - Stock in time - Stock out time" << endl << endl;
	for (int i = 0; i < _products.size(); i++)
	{
		_products[i].showProductInfoForStaff();
		cout << endl << endl;
	}
}

void Shop::showBillList()	
{
	for (int i = 0; i < _bills.size(); i++)
	{
		cout << _bills[i].toString() << endl;
	}
}

void Shop::showStaffList()
{
	sortStaffList();
	cout << "Name\t-\tDate of Birth\t-\tPhone Number\t-\tAddress\t-\tStaff ID\t-\tBase Salary\t-\tGoods Sale\t-\tSalary\n\n";
	for (int i = 0; i< _staffs.size(); i++)
	{
		_staffs[i]->showStaffInfo();
		cout << endl << endl;
	}
}

void Shop::showSellerList()
{
	sortStaffList();
	cout << "Name\t-\tDate of Birth\t-\tPhone Number\t-\tAddress\t-\tStaff ID\t-\tBase Salary\t-\tGoods Sale\t-\tSalary\n\n";
	for (int i = 0; i < _staffs.size(); i++)
	{
		if (dynamic_cast<Seller*> (_staffs[i]))
		{
			_staffs[i]->showStaffInfo();
			cout << endl << endl;
		}
	}
}

void Shop::showSecurityList()
{
	sortStaffList();
	cout << "Name\t-\tDate of Birth\t-\tPhone Number\t-\tAddress\t-\tID\t-\tSalary\n\n";
	for (int i = 0; i < _staffs.size(); i++)
	{
		if (dynamic_cast<Security*> (_staffs[i]))
		{
			_staffs[i]->showStaffInfo();
			cout << endl << endl;
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// <summary>
///			SWITCH\CASE			///
/// </summary>


void Shop::Start()
{
	bool is_continue = true;
	int choice;


	Menu::showMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (is_continue)
	{
		switch (choice)
		{
		case 1:

			try
			{
				Purchase();
			}
			catch (const std::exception& mess)
			{
				cout << mess.what() << endl;
			}
			break;

		case 2:

			if (!(Staff::login(_staffs)))
			{
				break;
			}


			ProductManagement();
			
			
			break;

		case 3:

			if (!(Staff::login(_staffs)))
			{
				break;
			}


			StaffInfoManagement();


			break;

		case 4:

			is_continue = false;
			continue;

		}


		system("pause");
		system("cls");


		Menu::showMenu();
		cout << "Choose: ";
		cin >> choice;
		cin.ignore();
	}
	
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// <summary>
///			Purchase		///
/// </summary>

void Shop::Purchase()
{
	system("cls");
	if (!(_products.size()))
	{
		throw exception("Out of stock");
	}


	showProductList();

	//vector <Product> products_sold;

	Product product;

	int index;
	string id;
	cout << "Enter product's id: ";
	getline(cin, id);

	int amount;
	cout << "Amount: ";
	cin >> amount;
	cin.ignore();

	vector <Product> cart;

	for (int i = 0; i < amount; i++)
	{
		if (Product::isValidInList(_products, id, index)) {
			product = Product::search_by_ProductId(_products, index);
			cart.push_back(product);
			
		}
		else if (!i)
		{
			cout << "Product is out of stock" << endl;
			return;
		}
		else
		{
			cout << "Product is out of stock" << endl;
		}
	}


	for (int i = 0; i < cart.size(); i++)
	{
		cart[i].showProductInfo();
		cout << endl << endl;
	}

	string order;
	cout << "Would you like to buy all products above? Yes or No: ";
	getline(cin, order);
	if (order == "yes" || order == "Yes")
	{
		Product::buyProduct(_products, _products_sold, product);
	}
	else if (order == "no" || order == "No")
	{
		for (int i = 0; i < cart.size(); i++)
		{
			_products.push_back(cart[i]);
			_products_sold.pop_back();
		}
		return;
	}


	Seller* seller = nullptr;
	bool is_found = false;
	do
	{
		try
		{
			seller = dynamic_cast <Seller*> (seller->search(_staffs));
			if (seller)
			{
				is_found = true;
			}
		}
		catch (const std::exception& mess)
		{
			cout << mess.what() << endl;
			if (!(strcmp(mess.what(), "Cancel!!!")))
			{
				for (int i = 0; i < cart.size(); i++)
				{
					_products.push_back(cart[i]);
					_products_sold.pop_back();
				}
				return;
			}
			is_found = false;
		}
	} while (!(is_found));
	seller->setGoodsSale(cart.size());
	seller->setCommission();
	updateList(_staffs, seller);


	long long int new_id = stoll(Bill::getLastBillID(_bills)) + 1;
	Account account;
	account = AccountManagement();
	Bill bill(to_string(new_id), account.getMemberShipLevel(), account.getMemberShip(), Date(), cart);
	addToList(_bills, bill);
	bill.showBillInfo();


	MembershipLevel update(account.getMemberShip().getLevel(), account.getMemberShip().getCummulativePoints() + cart.size());
	update.updateLevel();
	account.setMemberShip(update);
	updateList(_accounts, account);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// <summary>
///			Account Management		////
/// </summary>
/// return Account

Account Shop::AccountManagement()
{
	system("cls");
	bool is_continue = true;


	string id;
	Account new_account;


	int choice;
	Menu::showAccountMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (is_continue)
	{
		switch (choice)
		{
		case 1:

			cout << "Enter your account id: ";
			getline(cin, id);
			try
			{
				return Account::sign_in(_accounts, id);
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
			}
			break;

		case 2:

			new_account = new_account.sign_up(_accounts);
			return new_account;

		case 3:

			is_continue = false;
			continue;
		}
	}


	return new_account;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// <summary>
///			Product management		///
/// </summary>

void Shop::ProductManagement()
{

	system("cls");
	bool is_continue = true;


	Product new_product;
	string ID;
	

	int choice;
	Menu::showProductManagementMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (is_continue)
	{
		switch (choice)
		{
		case 1:

			showProductListForStaff();
			break;

		case 2:

			system("cls");
			try
			{
				new_product.set();
			}
			catch (const std::exception& mess)
			{
				cout << mess.what() << endl;
				break;
			}


			Product::addProductInFile(_products, new_product);
			break;

		case 3:

			system("cls");
			showProductList();
			cout << "Enter product's ID: ";
			getline(cin, ID);
			if (ID == "cancel")
			{
				cout << "Cancel!!!\n";
				break;
			}
			

			int index;
			while (Product::isValidInList(_products, ID, index))
			{
				if (!(Product::isValidInList(_products, ID, index)))
				{
					cout << "Not found\n";
					break;
				}
				Product::deleteProductInFile(_products, Product::search_by_ProductId(_products, index));
			}
			break;

		case 4:

			showBillList();
			break;

		case 5:

			while (Bill::isFoundInList(_bills, ID))
			{
				if (!Bill::isFoundInList(_bills, ID))
				{
					cout << "Not found\n";
					break;
				}
				Bill::deleteBill(_bills, Bill::search(_bills, ID));
			}

			break;

		case 6:

			is_continue = false;
			continue;

		}


		system("pause");
		system("cls");


		Menu::showProductManagementMenu();
		cout << "Choose: ";
		cin >> choice;
		cin.ignore();
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// <summary>
///			Staff management		///
/// </summary>

void Shop::StaffInfoManagement()
{
	system("cls");
	bool is_continue = true;


	Staff* staff = nullptr;


	int choice;
	Menu::showStaffMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (is_continue)
	{
		switch (choice)
		{
		case 1:

			showStaffList();
			break;

		case 2:

			try
			{
				staff = Staff::search(_staffs);
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				break;
			}


			staff->showStaffInfo();
			cout << endl;


			break;

		case 3:


			SellerInfoManagement();
			break;

		case 4:

			SecurityInfoManagement();
			break;

		case 5:

			is_continue = false;
			continue;
		}

		
		system("pause");
		system("cls");


		Menu::showStaffMenu();
		cout << "Choose: ";
		cin >> choice;
		cin.ignore();
	}
}

void Shop::SellerInfoManagement()
{
	system("cls");
	bool is_continue = true;
	int choice;


	Staff* seller;


	Menu::showSellerMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (is_continue)
	{
		switch (choice)
		{
		case 1:

			showSellerList();
			break;

		case 2:

			try
			{
				seller = Staff::search(_staffs);
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				break;
			}


			seller->showStaffInfo();
			cout << endl;


			break;

		case 3:

			try
			{
				seller = Staff::search(_staffs);
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				break;
			}

			cout << "Salary: " << dynamic_cast<Seller*> (seller)->getSalary() << endl;

			break;

		case 4:

			try
			{
				seller = Staff::search(_staffs);

			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				break;
			}

			cout << "Commission: " << dynamic_cast<Seller*> (seller)->getCommission() << endl;

			break;

		case 5:

			cout << "SELLER OF MONTH\n";
			Seller::bestSellerOfMonth(_staffs);
			break;

		case 6:

			seller = new Seller;
			seller->setLastID(_staffs);

			try
			{
				seller->setNewStaff();
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				if (seller)
				{
					delete seller;
				}
				break;
			}

			addToList(_staffs, seller);

			break;

		case 7:		///		Delete Staff information	///

			showStaffList();


			Staff* staff;
			staff = staff->search(_staffs);
			staff->deleteStaff(_staffs);


			break;

		case 8:

			is_continue = false;
			continue;

		}


		system("pause");
		system("cls");


		Menu::showSellerMenu();
		cout << "Choose: ";
		cin >> choice;
		cin.ignore();
	}
}

void Shop::SecurityInfoManagement()
{
	system("cls");
	bool is_continue = true;
	int choice;


	string id;
	Staff* security;


	Menu::showSecurityMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (is_continue)
	{
		switch (choice)
		{
		case 1:		///		Show Staff information		///

			showSecurityList();
			break;

		case 2:

			try
			{
				security = Staff::search(_staffs);
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				break;
			}
			
			security->showStaffInfo();

			break;

		case 3:

			try
			{
				security = Staff::search(_staffs);
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				break;
			}

			cout << "Salary: " << dynamic_cast<Security*> (security)->getSalary() << endl;
			break;

		case 4:		///		New Staff	///

			security = new Security;
			security->setLastID(_staffs);
			

			try
			{
				security->setNewStaff();
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				if (security)
				{
					delete security;
				}
				break;
			}


			addToList(_staffs, security);

			break;

		case 5:		///		Delete Staff infomation

			break;

		case 6:

			is_continue = false;
			continue;

		}


		system("pause");
		system("cls");


		Menu::showSecurityMenu();
		cout << "Choose: ";
		cin >> choice;
	}
}
