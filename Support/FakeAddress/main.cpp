#include "FakeAddress.h"

int main()
{
	srand(time(0));
	int i = 0;
	while (i < 20)
	{
		cout << string(FakeHCMAddress::next()) << endl;
		i++;
	}
	system("pause");
	return 0;
}