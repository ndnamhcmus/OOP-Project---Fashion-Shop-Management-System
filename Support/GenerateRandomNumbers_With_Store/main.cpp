#include "GenerateRandomNumbers_With_Store.h"

int main()
{
	Store store;

	store.generateRandomNumbers();
	cout << "10 random numbers:\n";
	store.showCurrentNumbers();

	cout << endl;

	store.getNumbersFromKeyboard("string");
	cout << "Numbers have inputted:\n";
	store.showCurrentNumbers();

	cout << endl;

	system("pause");
	return 0;
}