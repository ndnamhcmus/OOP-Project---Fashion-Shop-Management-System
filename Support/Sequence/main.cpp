#include "Sequence.h"

int main()
{
	Sequence normal;
	for (int i = 1; i <= 10; i++)
	{
		cout << normal.next() << "\t";
	}
	cout << endl;


	Random rng;
	Sequence storeSequence(rng.next(0, 3000), 3);
	for (int i = 1; i <= 10; i++)
	{
		cout << storeSequence.next() << "\t";
	}
	cout << endl;
	system("pause");
	return 0;
}