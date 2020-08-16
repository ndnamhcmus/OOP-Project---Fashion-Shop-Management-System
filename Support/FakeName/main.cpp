#include "FakeName.h"

int main()
{
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		cout << string(FakeName::next()) << endl;
	}
	system("pause");
	return 0;
}