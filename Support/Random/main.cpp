#include "Random.h"
#define MAX 10
#define MIN 0

int main()
{
	srand(time(0));

	Random rng;
	cout << rng.next(MIN, MAX);
	return 0;
}