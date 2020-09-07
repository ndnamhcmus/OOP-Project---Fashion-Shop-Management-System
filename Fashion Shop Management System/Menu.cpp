#include "Menu.h"

void Menu::showMenu()
{
	cout << "1. Start trading\n";
	cout << "2. Staff information\n";
	cout << "3. Cancel\n";
}

void Menu::continueMenu()
{
	cout << "Do you want to continue?\n";
	cout << "Press Y or N: ";
}

void Menu::showStaffMenu()
{
	cout << "1. Search information\n";
	cout << "2. Seller\n";
	cout << "3. Security\n";
	cout << "4. Cancel\n";
}

void Menu::showSellerMenu()
{
	cout << "1. Search information\n";
	cout << "2. Show salary\n";
	cout << "3. Show commission\n";
	cout << "4. Seller of the month\n";
	cout << "5. Cancel\n";
}

void Menu::showSecurityMenu()
{
	cout << "1. Search information\n";
	cout << "2. Show salary\n";
	cout << "3. Cancel\n";
}

