#include "FakeMail.h"

int main()
{
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		FakeEmail fake_email;
		cout << i + 1 << ": " << fake_email.getFakeEmail() << endl << endl;
	}
	system("pause");
	return 0;
}