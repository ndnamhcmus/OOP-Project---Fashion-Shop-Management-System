#include "Random.h"

int Random::next(int min, int max)
{
	return (min + rand() % (max + 1 - min));
}