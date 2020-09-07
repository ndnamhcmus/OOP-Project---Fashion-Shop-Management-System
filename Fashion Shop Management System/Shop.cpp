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

void Shop::Start()
{
	string is_continue;
	int choice;


	Menu::showMenu();
	cout << "Choose: ";
	cin >> choice;
	while (!(is_continue == "n" || is_continue == "N"))
	{
		switch (choice)
		{
		case 1:

			Trading();
			break;

		case 2:

			StaffInfo();
			break;

		}


		system("cls");
		Menu::showMenu();
		Menu::continueMenu();
		cin.ignore();
		getline(cin, is_continue);
		system("cls");
		if (is_continue == "n")
		{
			continue;
		}


		cout << "Choose: ";
		cin >> choice;
	}
	
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

void Shop::StaffInfo()
{
	system("cls");
	string is_continue;


	int choice;
	Menu::showStaffMenu();
	cin >> choice;
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

			Menu::showSecurityMenu();
			break;

		case 4:

			is_continue = "n";
			continue;

		}


		system("cls");
		Menu::showStaffMenu();
		Menu::continueMenu();
		cin.ignore();
		getline(cin, is_continue);
		system("cls");
		if (is_continue == "n")
		{
			continue;
		}


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
		Menu::continueMenu();
		cin.ignore();
		getline(cin, is_continue);
		system("cls");
		if (is_continue == "n")
		{
			continue;
		}


		cout << "Choose: ";
		cin >> choice;
	}
}
