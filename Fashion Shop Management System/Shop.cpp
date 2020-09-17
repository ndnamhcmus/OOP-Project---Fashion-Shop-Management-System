#include "Shop.h"



/// <summary>
/// Load list
/// </summary>

void Shop::openProductList()
{
	Product::setProductsInfo(_products);
}

void Shop::openBillList()
{
	Bill::openBillFile(_bills);
}

void Shop::openAccountList()
{
	Account::openAccountFile(_accounts);
}

void Shop::openStaffList()
{
	Staff::openStaffToRead(_staffs);
}

/// <summary>
///		Save	///
/// </summary>

void Shop::saveProductList()
{

}

void Shop::saveBillList()
{
	Bill::saveBillToFile(_bills);
}

void Shop::saveAccountList()
{
	Account::saveAccountToFile(_accounts);
}

void Shop::saveStaffList()
{
	Staff::saveStaffInfoToFile(_staffs);
}

/// <summary>
///		Sort	///
/// </summary>
/// <param name="sort_by"></param>

void Shop::sortProduct()
{
	Product::sort(_products, "_product_id");
}

void Shop::sortAccount()
{
	Account account;
	account.sort(_accounts, "id");
}

void Shop::sortStaff(string sort_by)
{
}

/// <summary>
///		Show	///
/// </summary>
void Shop::showProductList()
{
	Product::showProductsInfo(_products);
}

void Shop::showStaffList()
{
	for (int i = 0; i< _staffs.size(); i++)
	{
		_staffs[i]->showStaffInfo();
		cout << endl;
	}
}

void Shop::showSellerList()
{
	cout << "Name\tDate of Birth\tPhone Number\tAddress\tStaff ID\tBase Salary\tGoods Sale\tSalary\n";
	for (int i = 0; i < _staffs.size(); i++)
	{
		if (dynamic_cast<Seller*> (_staffs[i]))
		{
			_staffs[i]->showStaffInfo();
			cout << endl;
		}
	}
}

void Shop::showSecurityList()
{
	for (int i = 0; i < _staffs.size(); i++)
	{
		if (dynamic_cast<Security*> (_staffs[i]))
		{
			_staffs[i]->showStaffInfo();
			cout << endl;
		}
	}
}

////////////////////		SWITCH\CASE		////////////////////

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

			Purchase();
			break;

		case 2:

			ProductManagement();
			break;

		case 3:

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

/// <summary>
///			Purchase		///
/// </summary>

void Shop::Purchase()
{
	system("cls");


	cout << "Product list\n";
	showProductList();


	vector <Product> products_sold;
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
			Product::buyProduct(_products, products_sold, product);

			cart.push_back(product);
		}
		else
		{
			cout << "the product is out of stock" << endl;
			return;
		}
	}


	long long int new_id = stoll(Bill::getLastBillID(_bills)) + 1;
	Account account;
	account = AccountManagement();
	Bill bill(to_string(new_id), account.getMemberShipLevel(), account.getMemberShip(), Date(), cart);
	_bills.push_back(bill);
	bill.showBillInfo();


	MembershipLevel update(account.getMemberShip().getLevel(), account.getMemberShip().getCummulativePoints() + cart.size());
	update.updateLevel();
	account.setMemberShip(update);
	updateList(_accounts, account);
}

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

/// <summary>
///			Product management		///
/// </summary>

void Shop::ProductManagement()
{

	system("cls");
	bool is_continue = true;


	Product new_product;
	string id;
	

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

			system("cls");
			if (new_product.set() == "cancel")
			{
				break;
			}
			Product::addProductInFile(_products, new_product);
			break;

		case 2:

			system("cls");
			showProductList();
			cout << "Enter product's ID: ";
			getline(cin, id);
			if (id == "cancel")
			{
				cout << "Cancel!!!\n";
				break;
			}
			

			int index;
			while (Product::isValidInList(_products, id, index))
			{
				if (!(Product::isValidInList(_products, id, index)))
				{
					cout << "Not found\n";
				}
				Product::deleteProductInFile(_products, Product::search_by_ProductId(_products, index));
			}
			break;

		case 3:

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

			_staffs.push_back(seller);

			break;

		case 7:

			is_continue = false;
			continue;

		}


		system("pause");
		system("cls");


		Menu::showSellerMenu();
		cout << "Choose: ";
		cin >> choice;
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
		case 1:

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

		case 4:

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


			_staffs.push_back(security);

			break;

		case 5:

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
