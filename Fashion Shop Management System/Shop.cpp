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

/// <summary>
///		Sort	///
/// </summary>
/// <param name="sort_by"></param>

void Shop::sortProduct(string sort_by)
{
	Product::sort(_products, "");
}

void Shop::sortAccount(string sort_by)
{
	Account account;
	account.sort(_accounts, sort_by);
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

////////////////////		SWITCH\CASE		////////////////////

void Shop::Start()
{
	string is_continue;
	int choice;


	Menu::showMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (!(is_continue == "n" || is_continue == "N"))
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

			is_continue = "n";
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

			cout << "product has been purchased" << endl;
		}
		else
		{
			cout << "the product is out of stock" << endl;
		}
	}


	long long int new_id = stoll(Bill::lastBill_ID_InFile()) + 1;
	Bill bill(to_string(new_id), Date(), cart);
	_bills.push_back(bill);
	bill.showBillInfo();
}

void Shop::ProductManagement()
{

	system("cls");
	string is_continue;


	Product product;
	string id;
	

	int choice;
	Menu::showProductManagementMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (!(is_continue == "n" || is_continue == "N"))
	{
		switch (choice)
		{
		case 1:


			//Product::addProductInFile()
			break;

		case 2:

			showProductList();
			cout << "Enter product's ID: ";
			getline(cin, id);
			//Product::deleteProductInFile();
			break;

		case 3:

			is_continue = "n";
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

void Shop::StaffInfoManagement()
{
	system("cls");
	string is_continue;


	int choice;
	Menu::showStaffMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (!(is_continue == "n" || is_continue == "N"))
	{
		switch (choice)
		{
		case 1:

			break;

		case 2:

			SellerInfo();
			break;

		case 3:

			SecurityInfo();
			break;

		case 4:

			is_continue = "n";
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

void Shop::SellerInfo()
{
	system("cls");
	string is_continue;
	int choice;


	string id;


	Menu::showSellerMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (!(is_continue == "n" || is_continue == "N"))
	{
		switch (choice)
		{
		case 1:

			break;

		case 2:

			cout << "Enter seller id: ";
			
			getline(cin, id);

			
			for (int i = 0; i < _staffs.size(); i++)
			{

			}
			break;

		case 3:

			break;

		case 4:

			break;

		case 5:

			is_continue = "n";
			continue;

		}


		/*system("cls");
		Menu::showSellerMenu();
		Menu::continueMenu(55, 5);
		getline(cin, is_continue);
		system("cls");
		if (is_continue == "n")
		{
			continue;
		}*/
		system("pause");
		system("cls");


		Menu::showSellerMenu();
		cout << "Choose: ";
		cin >> choice;
	}
}

void Shop::SecurityInfo()
{
	system("cls");
	string is_continue;
	int choice;


	string id;


	Menu::showSecurityMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (!(is_continue == "n" || is_continue == "N"))
	{
		switch (choice)
		{
		case 1:

			break;

		case 2:

			break;

		case 3:

			is_continue = "n";
			continue;

		}


		/*system("cls");
		Menu::showSecurityMenu();
		Menu::continueMenu(55, 3);
		getline(cin, is_continue);
		system("cls");
		if (is_continue == "n")
		{
			continue;
		}*/
		system("pause");
		system("cls");


		Menu::showSecurityMenu();
		cout << "Choose: ";
		cin >> choice;
	}
}
