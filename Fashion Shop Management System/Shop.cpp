#include "Shop.h"

void Shop::openProductList()
{

}

void Shop::sortProduct(string sort_by)
{
	Product product;
}

void Shop::sortAccount(string sort_by)
{
	Account account;
	account.sort(_accounts, sort_by);
}

void Shop::sortStaff(string sort_by)
{
}

void Shop::showProductList()
{
	for (int i = 0; i < _products.size(); i++)
	{
		cout << i + 1 << ": ";
		_products[i].showProductInfo();
		cout << endl;
	}
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

			Trading();
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


		/*system("cls");
		Menu::showMenu();
		Menu::continueMenu(55, 3);
		getline(cin, is_continue);
		system("cls");
		if (is_continue == "n")
		{
			continue;
		}*/
		system("pause");
		system("cls");


		Menu::showMenu();
		cout << "Choose: ";
		cin >> choice;
		cin.ignore();
	}
	
}

void Shop::Trading()
{
	system("cls");


	int amount;


	cout << "Product list\n";
	showProductList();


	Product product;
	string id;
	cout << "Enter product id: ";
	getline(cin, id);
	product = Product::search_by_ProductId(_products, id);


	vector <Product> cart;
	cout << "Amount: ";
	cin >> amount;
	cin.ignore();
	for (int i = 0; i < amount; i++)
	{
		cart.push_back(product);
	}

}

void Shop::ProductManagement()
{
	string id;
	Product product;


	product.addProduct(_products, product);
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


		
		/*Menu::showStaffMenu();
		Menu::continueMenu(55, 4);
		getline(cin, is_continue);
		system("cls");
		if (is_continue == "n")
		{
			continue;
		}*/
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
