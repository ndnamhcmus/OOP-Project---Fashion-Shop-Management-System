#pragma once

#include <iostream>
#include <Random.h>

using namespace std;

class Dice
{
private:
	Random _rng;


	int _count_rolls_times = 0;
	int _value_of_all_rolls = 0;
	int a[7] = { -1,0,0,0,0,0,0 };

public:
	int roll();

	int getCount();

	double getAverageRollValue();

	void printCountValue();
};
