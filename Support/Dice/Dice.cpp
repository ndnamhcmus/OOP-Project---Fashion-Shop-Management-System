#include "Dice.h"


int Dice::roll()
{
	int rng = _rng.next(1, 6);


	++_count_rolls_times;
	_value_of_all_rolls = _value_of_all_rolls + rng;


	switch (rng)
	{
	case 1:
		a[1]++;
		break;
	case 2:
		a[2]++;
		break;
	case 3:
		a[3]++;
		break;
	case 4:
		a[4]++;
		break;
	case 5:
		a[5]++;
		break;
	case 6:
		a[6]++;
		break;
	}


	return rng;
}

int Dice::getCount()
{
	return _count_rolls_times;
}

double Dice::getAverageRollValue()
{
	return double(_value_of_all_rolls) / _count_rolls_times;
}

void Dice::printCountValue()
{
	for (int i = 0; i < 7; i++)
	{
		if (!i)
		{
			continue;
		}
		else
		{
			cout << i << " times: " << a[i] << endl;
		}
	}
}