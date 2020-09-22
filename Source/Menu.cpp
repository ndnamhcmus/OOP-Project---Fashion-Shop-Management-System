#include "Menu.h"


stringstream Menu::_buffer;


void Menu::showMenu()
{
	int x = 115;
	int y = 5;

	_buffer << "Welcome to 19CLC6\n";
	gotoxy(x - _buffer.str().size() / 2, 0);
	cout << _buffer.str();
	_buffer.str("");


	_buffer << "1. Purchase\n";
	gotoxy(x - _buffer.str().size() / 2, y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "2. Product management\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "3. Staff information management\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "4. Account information\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "5. Save and Exit\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");
}

void Menu::continueMenu(int x, int y)
{
	_buffer << "Do you want to continue?\n";
	gotoxy(x - _buffer.str().size() / 2, y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "Press Y or N: ";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");
}

void Menu::showProductManagementMenu()
{
	int x = 115, y = 0;

	_buffer << "1. Show product list\n";
	gotoxy(x - _buffer.str().size() / 2, y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "2. Add new product\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "3. Delete product\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");
	
	_buffer << "4. Show Bill list\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "5. Delete bill\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "6. Show purchase history\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "7. Exit\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");
}

void Menu::showAccountMenu()
{
	int x = 115, y = 0;

	_buffer << "1. Sign in\n";
	gotoxy(x - _buffer.str().size() / 2, y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "2. Sign up\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "3. Exit\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");
}

void Menu::showStaffMenu()
{
	int x = 115, y = 0;

	_buffer << "1. Show Staff list\n";
	gotoxy(x - _buffer.str().size() / 2, y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "2. Search information\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "3. Seller\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "4. Security\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "5. Exit\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

}

void Menu::showSellerMenu()
{
	int x = 115, y = 0;


	_buffer << "1. Show Seller list\n";
	gotoxy(x - _buffer.str().size() / 2, y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "2. Search information\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "3. Show salary\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "4. Show sales\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "5. Show commission\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "6. Seller of the month\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "7. Add new Staff\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "8. Delete Staff\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "9. Exit\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");
}

void Menu::showSecurityMenu()
{
	int x = 115, y = 0;


	_buffer << "1. Show Securtity list\n";
	gotoxy(x - _buffer.str().size() / 2, y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "2. Search information\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "3. Show salary\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "4. Add new staff\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "5. Delete staff\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "6. Exit\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");
}

