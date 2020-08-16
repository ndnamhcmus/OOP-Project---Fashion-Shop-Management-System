#include "Dice.h"

int main()
{
	srand(time(0));


	Dice dice;
	int choose;
	int sum_of_all_rolls = 0;
	int value;


	cout << "Roll: Press any key\n";
	cout << "Cancel: Press 0\n";
	cin >> choose;
	while (true)
	{
		value = dice.roll();
		cout << "Dice value: " << value << endl;
		sum_of_all_rolls = sum_of_all_rolls + value;


		cout << "Roll: Press any key\n";
		cout << "Cancel: Press 0\n";
		cin >> choose;
		if (!choose)
		{
			break;
		}
	}
	cout << "Rolls times: " << dice.getCount() << endl;
	cout << "Average value: " << dice.getAverageRollValue() << endl;
	dice.printCountValue();


	system("pause");
	return 0;
}