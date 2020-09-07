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

			AddProduct();
			break;

		case 3:

			StaffInfo();
			break;

		case 4:

			is_continue = "n";
			continue;

		}


		system("cls");
		Menu::showMenu();
		Menu::continueMenu(55, 3);
		getline(cin, is_continue);
		system("cls");
		if (is_continue == "n")
		{
			continue;
		}


		Menu::showMenu();
		cout << "Choose: ";
		cin >> choice;
	}
	
}

void Shop::Trading()
{
	system("cls");


	int choice;
	int amount;


	cout << "Product list\n";
	showProductList();


	cout << "Choose: ";
	Product product;
	product;
	cout << "Amount: ";
	cin >> amount;



}

void Shop::AddProduct()
{

}

void Shop::StaffInfo()
{
	system("cls");
	string is_continue;


	int choice;
	Menu::showStaffMenu();
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


		system("cls");
		Menu::showStaffMenu();
		Menu::continueMenu(55, 4);
		getline(cin, is_continue);
		system("cls");
		if (is_continue == "n")
		{
			continue;
		}


		Menu::showStaffMenu();
		cout << "Choose: ";
		cin >> choice;
	}
}

void Shop::SellerInfo()
{
	system("cls");
	string is_continue;
	int choice;


	string id;


	Menu::showSellerMenu();
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


		system("cls");
		Menu::showSellerMenu();
		Menu::continueMenu(55, 5);
		getline(cin, is_continue);
		system("cls");
		if (is_continue == "n")
		{
			continue;
		}


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


		system("cls");
		Menu::showSecurityMenu();
		Menu::continueMenu(55, 3);
		getline(cin, is_continue);
		system("cls");
		if (is_continue == "n")
		{
			continue;
		}


		Menu::showSecurityMenu();
		cout << "Choose: ";
		cin >> choice;
	}
}
