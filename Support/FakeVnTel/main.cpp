#include "FakeVnTel.h"

int main()
{
	srand(time(0));

	
	for (int i = 0; i < 20; i++)
	{
		FakeVnTel tels;
		cout << tels.getVnTel() << endl << endl;
	}
	system("pause");
	return 0;
}