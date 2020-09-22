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
		Product::openProductList(_products_sold, "../Fashion Shop Management System/Database/Product Sold.csv");
	}
	catch (const std::exception& mess)
	{
		Menu::gotoxy(115 - strlen(mess.what()) / 2, 0);
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
		Menu::gotoxy(115 - strlen(mess.what()) / 2, 0);
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
		Menu::gotoxy(115 - strlen(mess.what()) / 2, 0);
		cout << mess.what() << endl;
		system("pause");
		system("cls");
	}


	for (auto& account : _accounts)
	{
		for (auto& bill : _bills)
		{
			if (account.getID() == bill.getAccountID())
			{
				account.addBill(bill);
			}
		}
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
		Menu::gotoxy(115 - strlen(mess.what()) / 2, 0);
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
		Product::saveProductList(_products_sold, "../Fashion Shop Management System/Database/Product Sold.csv");
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

vector <Staff*>Shop::_staffs;
void Shop::sortStaffList(string sort_by, vector <Staff*> staffs)
{
	Staff::sort(staffs, sort_by);
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
	while (sort_by == "")
	{
		getline(cin, sort_by);
	}
	if (sort_by == "cancel")
	{
		cout << "Cancel!!!" << endl;
		return;
	}
	transform(sort_by.begin(), sort_by.end(), sort_by.begin(), ::tolower);	//	chuyển về chữ thường


	Product::sort(_products, sort_by);
	cout << "PRODUCT LIST\n";
	Product::showProductsInfo(_products);
}

void Shop::showPurchaseHistory()
{
	Product::showProductsInfo(_products_sold);
}

void Shop::showProductListForStaff()
{
	cout << "Sort by: Name\tID\tFirm Name\tType\tColor\tSize\tCost\tPrice\tDiscount\n";


	string sort_by;
	cout << "Choose: ";
	while (sort_by == "")
	{
		getline(cin, sort_by);
	}
	if (sort_by == "cancel")
	{
		cout << "Cancel!!!" << endl;
		return;
	}
	transform(sort_by.begin(), sort_by.end(), sort_by.begin(), ::tolower);	//	chuyển về chữ thường


	Product::sort(_products, sort_by);
	cout << "PRODUCT LIST\n";
	cout << "Product name - Product ID - Firm name - Product type - Product color - Product size - Product cost - Product price - Discount - Stock in time - Stock out time" << endl << endl;
	for (int i = 0; i < _products.size(); i++)
	{
		cout << i + 1 << ": ";
		_products[i].showProductInfoForStaff();
		cout << endl << endl;
	}
}

void Shop::showBillList()	
{
	cout << "BILL LIST\n";
	cout << "Bill ID\tDate\tProduct Name\tProduct Price\tTotal\tAccount ID" << endl;
	for (int i = 0; i < _bills.size(); i++)
	{
		cout << i + 1 << ": ";
		cout << _bills[i].toString() << endl;
	}
}

void Shop::showStaffList()
{
	string sort_by;
	cout << "Sort by:\tID\tSalary" << endl;
	cout << "Choose: ";
	while (sort_by == "")
	{
		getline(cin, sort_by);
	}
	if (sort_by == "cancel")
	{
		cout << "Cancel!!!" << endl;
		return;
	}
	transform(sort_by.begin(), sort_by.end(), sort_by.begin(), ::tolower);	//	chuyển về chữ thường


	sortStaffList(sort_by);
	cout << "STAFF LIST" << endl;
	cout << "Name\t-\tDate of Birth\t-\tPhone Number\t-\tAddress\t-\tStaff ID\t-\tBase Salary\t-\tSales\t-\tSalary\n\n";
	for (int i = 0; i< _staffs.size(); i++)
	{
		cout << i + 1 << ": ";
		_staffs[i]->showStaffInfo();
		cout << endl << endl;
	}
}

void Shop::showSellerList()
{
	vector <Staff*> sellers;
	for (int i = 0; i < _staffs.size(); i++)
	{
		if (dynamic_cast <Seller*> (_staffs[i]))
		{
			sellers.push_back(dynamic_cast <Seller*> (_staffs[i]));
		}
	}


	string sort_by;
	cout << "Sort by:\tID\tSales\tSalary" << endl;
	cout << "Choose: ";
	while (sort_by == "")
	{
		getline(cin, sort_by);
	}
	if (sort_by == "cancel")
	{
		cout << "Cancel!!!" << endl;
		return;
	}
	transform(sort_by.begin(), sort_by.end(), sort_by.begin(), ::tolower);	//	chuyển về chữ thường


	sortStaffList(sort_by, sellers);
	cout << "SELLER LIST" << endl;
	cout << "Name\t-\tDate of Birth\t-\tPhone Number\t-\tAddress\t-\tStaff ID\t-\tBase Salary\t-\tSales\t-\tReal Salary\n\n";
	for (int i = 0; i < _staffs.size(); i++)
	{
		if (dynamic_cast<Seller*> (_staffs[i]))
		{
			cout << i + 1 << ": ";
			_staffs[i]->showStaffInfo();
			cout << endl << endl;
		}
	}


}

void Shop::showSecurityList()
{
	string sort_by;
	cout << "Sort by:\tID\tSalary" << endl;
	cout << "Choose: ";
	while (sort_by == "")
	{
		getline(cin, sort_by);
	}
	if (sort_by == "cancel")
	{
		cout << "Cancel!!!" << endl;
		return;
	}
	transform(sort_by.begin(), sort_by.end(), sort_by.begin(), ::tolower);	//	chuyển về chữ thường


	sortStaffList(sort_by);
	cout << "SECURITY LIST" << endl;
	cout << "Name\t-\tDate of Birth\t-\tPhone Number\t-\tAddress\t-\tID\t-\tSalary\n\n";
	for (int i = 0; i < _staffs.size(); i++)
	{
		if (dynamic_cast<Security*> (_staffs[i]))
		{
			cout << i + 1 << ": ";
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
	string ID;


	Account account;


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

			
			account = AccountManagement();
			if (account.getID() == "")
			{
				break;
			}
			cout << endl;
			cout << "BILL LIST" << endl << endl;
			account.showBillList();


			break;

		case 5:

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

void Shop::bestSelling()
{
	vector <string> product_name_list;
	product_name_list = Product::getBestSelling();


	SHORT x = 115, y = _products.size() * 2 + 6;
	stringstream buffer;
	buffer << "BEST SELLING";
	Menu::gotoxy(x - buffer.str().size() / 2, y);


	cout << buffer.str() << endl << endl;
	for (const auto& product_name : product_name_list)
	{
		cout << product_name << endl << endl;
	}
}

void Shop::Purchase()
{
	system("cls");
	if (!(_products.size()))
	{
		throw exception("Out of stock");
	}


	Product product;
	vector <Product> cart;


	while (true)
	{
		showProductList();
		bestSelling();


		string ID;
		cout << "Enter Product ID: ";
		while (ID == "")
		{
			getline(cin, ID);
		}
		if (ID == "cancel")
		{
			cout << "Cancel!!!" << endl;
			return;
		}
		int amount;
		cout << "Amount: ";
		cin >> amount;
		cin.ignore();


		for (int i = 0; i < amount; i++)
		{
			int index;
			try
			{
				Product::isValidInList(_products, ID, index);
			}
			catch (const std::exception& mess)
			{
				if (!(strcmp(mess.what(), "Product not found")))
				{
					cout << "Add to cart failed" << endl;
					continue;
				}
			}
			product = product.search_by_ProductId(_products, index);
			cart.push_back(product);
			cout << "Add to cart successfully\n";


			product.buyProduct(_products, _products_sold);
		}


		if (cart.size())
		{
			break;
		}
		else
		{
			cout << "\nYour cart is empty, try again\n";
			system("pause");
			system("cls");
		}
	}


	system("pause");
	system("cls");


	for (int i = 0; i < cart.size(); i++)
	{
		cart[i].showProductInfo();
		cout << endl << endl;
	}


	string order;
	cout << "Would you like to buy all products above? Yes or No: ";
	while (order == "")
	{
		getline(cin, order);
	}


	if (order == "yes" || order == "Yes")
	{
		system("cls");
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


	/// <summary>
	///		Chuẩn bị bill mua hàng		///
	/// </summary>
	long long int new_id = stoll(Bill::getLastBillID(_bills)) + 1;
	Account account;
	account = AccountManagement();
	Bill bill(to_string(new_id), account.getMembershipLevel(), account.getMemberShip(), Date(), cart, account.getID());
	addToList(_bills, bill);
	bill.showBillInfo();


	/// <summary>
	///			Tích luỹ điểm cho Account		///
	/// </summary>
	MembershipLevel update(account.getMemberShip().getLevel(), account.getMemberShip().getCummulativePoints() + cart.size());
	update.updateLevel();
	account.setMemberShip(update);
	updateList(_accounts, account);


	/// <summary>
	///			Tính doanh số bán hàng cho nhân viên		///
	/// </summary>
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
	seller->updateSales(cart.size());
	seller->updateSalary();
	updateList(_staffs, seller);
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


	string ID;
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
			do
			{
				getline(cin, ID);
			} while (ID == "");


			try
			{
				return Account::sign_in(_accounts, ID);
			}
			catch (const std::exception& mess)
			{
				cout << mess.what() << endl;
				if (!(strcmp(mess.what(), "Cancel!!!")))
				{
					break;
				}
			}


			break;

		case 2:


			while (true)
			{
				try
				{
					new_account.sign_up(_accounts);
					if (new_account.getID() != "")
					{
						return new_account;
					}
				}
				catch (const std::exception& mess)
				{
					cout << mess.what() << endl;
					if (!(strcmp(mess.what(), "Cancel!!!")))
					{
						break;
					}
					system("pause");
					system("cls");
				}
			}


			break;

		case 3:

			is_continue = false;
			continue;
		}


		system("pause");
		system("cls");


		Menu::showAccountMenu();
		cout << "Choose: ";
		cin >> choice;
		cin.ignore();
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


	Product product;
	Product new_product;
	Bill bill;

	string ID;
	string delete_amount;
	

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
			while (true)
			{
				try
				{
					new_product.set();
					if (new_product.getProductId() != "")
					{
						break;
					}
				}
				catch (const std::exception& mess)
				{
					cout << mess.what() << endl;


					if (!(strcmp(mess.what(), "Cancel!!!")))
					{
						break;
					}
					system("pause");
					system("cls");
				}
			}
			if (!(new_product.getProductId() != ""))
			{
				break;
			}


			int amount;
			cout << "Amount: ";
			cin >> amount;
			cin.ignore();
			for (int i = 0; i < amount; i++)
			{
				new_product.addProductInFile(_products);
			}


			system("cls");
			showProductListForStaff();



			break;

		case 3:

			system("cls");
			showProductList();
			cout << "Enter product's ID: ";
			do
			{
				getline(cin, ID);
			} while (ID == "");


			if (ID == "cancel")
			{
				cout << "Cancel!!!\n";
				break;
			}
			
			int index;
			cout << "Amount: ";
			getline(cin, delete_amount);
			if (delete_amount == "all")
			{
				while (true)
				{
					try
					{
						Product::isValidInList(_products, ID, index);
					}
					catch (const std::exception& mess)
					{
						if (!(strcmp(mess.what(), "Product not found")))
						{
							break;
						}
					}
					product.search_by_ProductId(_products, index);
					product.deleteProduct(_products);
				}
			}
			else if (delete_amount >= "0" && delete_amount <= "9")
			{
				int count = stoi(delete_amount);
				while (count)
				{
					try
					{
						Product::isValidInList(_products, ID, index);
					}
					catch (const std::exception& mess)
					{
						cout << mess.what() << endl;
						if (!(strcmp(mess.what(), "Product not found")))
						{
							system("pause");
							break;
						}
					}
					product.search_by_ProductId(_products, index);
					product.deleteProduct(_products);
					count--;
				}
			}


			system("cls");
			showProductListForStaff();


			break;

		case 4:

			showBillList();
			break;

		case 5:

			showBillList();

			cout << "Enter your Bill ID: ";
			getline(cin, ID);


			do
			{
				try
				{
					bill.search(_bills, ID);
				}
				catch (const std::exception& mess)
				{
					cout << mess.what() << endl;
					break;
				}
				try
				{
					bill.deleteBill(_bills);
				}
				catch (const std::exception& mess)
				{
					cout << mess.what() << endl;
					system("pause");
				}
			} while (Bill::isFoundInList(_bills, ID));


			system("cls");
			showBillList();


			break;

		case 6:

			showPurchaseHistory();
			break;

		case 7:

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
				staff = staff->search(_staffs);
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				break;
			}


			cout << "Name\t-\tDate of Birth\t-\tPhone Number\t-\tAddress\t-\tStaff ID\t-\tBase Salary\t-\tSales\t-\tSalary\n\n";
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


	Staff* seller = nullptr;


	Menu::showSellerMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (is_continue)
	{
		switch (choice)
		{
		case 1:		///		Show information		///

			showSellerList();
			break;

		case 2:

			try
			{
				seller = seller->search(_staffs);
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				break;
			}
			

			cout << "Name\t-\tDate of Birth\t-\tPhone Number\t-\tAddress\t-\tStaff ID\t-\tBase Salary\t-\tSales\t-\tSalary\n\n";
			seller->showStaffInfo();
			cout << endl;


			break;

		case 3:

			try
			{
				seller = seller->search(_staffs);
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				break;
			}

			cout << "Salary: " << to_string(dynamic_cast<Seller*> (seller)->getSalary()) << endl;

			break;
		case 4:



			try
			{
				seller = seller->search(_staffs);
			}
			catch (const std::exception& mess)
			{
				cout << mess.what() << endl;
				break;
			}

			cout << "Sales: " << dynamic_cast <Seller*> (seller)->getSales() << endl;


			break;

		case 5:

			try
			{
				seller = seller->search(_staffs);

			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				break;
			}

			cout << "Commission: " << dynamic_cast<Seller*> (seller)->getCommission() << endl;

			break;

		case 6:		///		Seller of month		///

			cout << "SELLER OF MONTH\n";
			Seller::bestSellerOfMonth(_staffs);
			break;

		case 7:		///		Add new staff		///

			seller = new Seller;
			seller->setLastID(_staffs);

			while (true)
			{
				try
				{
					seller->setNewStaff();
					if (seller)
					{
						break;
					}
				}
				catch (const std::exception& mess)
				{
					cout << mess.what() << endl;


					if (!(strcmp(mess.what(), "Cancel!!!")))
					{
						if (seller)
						{
							delete seller;
						}
						seller = nullptr;
						break;
					}
					system("pause");
					system("cls");
				}
			}
			

			if (!(seller))
			{
				break;
			}


			addToList(_staffs, seller);


			system("cls");
			showSellerList();


			break;

		case 8:		///		Delete Staff information	///

			showSellerList();


			try
			{
				seller = seller->search(_staffs);
			}
			catch (const std::exception& mess)
			{
				cout << mess.what() << endl;
				break;
			}
			seller->deleteStaff(_staffs);


			system("cls");
			showSellerList();


			break;

		case 9:

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
				security = security->search(_staffs, "Security");
				if (dynamic_cast <Seller*> (security))
				{
					throw exception("Not a Security");
				}
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				break;
			}
			

			cout << "Name\t-\tDate of Birth\t-\tPhone Number\t-\tAddress\t-\tID\t-\tSalary\n\n";
			security->showStaffInfo();


			break;

		case 3:

			try
			{
				security = security->search(_staffs, "Security");
				if (dynamic_cast <Seller*> (security))
				{
					throw exception("Not a Security");
				}
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
				break;
			}

			cout << "Salary: " << to_string(dynamic_cast<Security*> (security)->getSalary())<< endl;


			break;

		case 4:		///		New Staff	///

			security = new Security;
			security->setLastID(_staffs);
			

			while (true)
			{
				try
				{
					security->setNewStaff();
					if (security)
					{
						break;
					}
				}
				catch (const std::exception& mess)
				{
					cout << mess.what() << endl;


					if (!(strcmp(mess.what(), "Cancel!!!")))
					{
						if (security)
						{
							delete security;
						}
						security = nullptr;
						break;
					}
					system("pause");
					system("cls");
				}
			}
			

			if (!(security))
			{
				break;
			}


			addToList(_staffs, security);


			system("cls");
			showSecurityList();


			break;

		case 5:		///		Delete Staff infomation

			showSecurityList();

			try
			{
				security = security->search(_staffs, "Security");
				if (dynamic_cast <Seller*> (security))
				{
					throw exception("Not a Security");
				}
			}
			catch (const std::exception& mess)
			{
				cout << mess.what() << endl;
				break;
			}
			security->deleteStaff(_staffs);


			system("cls");
			showSecurityList();


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
		cin.ignore();
	}
}
