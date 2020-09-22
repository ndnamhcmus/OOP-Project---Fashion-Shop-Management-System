#include "Shop.h"

#include <windows.h>
void maximizeWindow() {
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}

int main()
{
	maximizeWindow();


	Shop shop;
	shop.Start();


	cout << endl;
	system("pause");
	return 0;
}