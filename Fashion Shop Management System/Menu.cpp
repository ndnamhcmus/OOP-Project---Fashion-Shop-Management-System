#include "Menu.h"


stringstream Menu::_buffer;


void Menu::showMenu()
{
	int x = 55;
	int y = 5;

	_buffer << "Welcome to\n";
	gotoxy(x - _buffer.str().size() / 2, 0);
	cout << _buffer.str();
	_buffer.str("");


	_buffer << "1. Start trading\n";
	gotoxy(x - _buffer.str().size() / 2, y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "2. Add new product\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "3. Staff information\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "4. Cancel\n";
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

void Menu::showStaffMenu()
{
	int x = 55, y = 0;


	_buffer << "1. Search information\n";
	gotoxy(x - _buffer.str().size() / 2, y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "2. Seller\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "3. Security\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "4. Cancel\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

}

void Menu::showSellerMenu()
{
	int x = 55, y = 0;
	_buffer << "1. Search information\n";
	gotoxy(x - _buffer.str().size() / 2, y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "2. Show salary\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "3. Show commission\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "4. Seller of the month\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "5. Cancel\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");
}

void Menu::showSecurityMenu()
{
	int x = 55, y = 0;
	_buffer << "1. Search information\n";
	gotoxy(x - _buffer.str().size() / 2, y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "2. Show salary\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");

	_buffer << "3. Cancel\n";
	gotoxy(x - _buffer.str().size() / 2, ++y);
	cout << _buffer.str();
	_buffer.str("");
}

