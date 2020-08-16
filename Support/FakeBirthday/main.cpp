#include "FakeBirthday.h"

int main()
{
	srand(time(0));


	FakeBirthday fake_birthday;


	cout << "Birth day: ";
	cout << string(fake_birthday.next()) << endl;
	cout << "Age: ";
	cout << fake_birthday.getAge() << endl;

	system("pause");
	return 0;
}