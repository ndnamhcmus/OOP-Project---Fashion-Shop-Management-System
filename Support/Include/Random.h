#ifndef _RANDOM_
#define _RANDOM_


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Random
{
public:
	int next(int min, int max = 0);
};


#endif