#include <iostream>
#include <Random.h>
using namespace std;


class Sequence
{
private:
	static int _bill;


	int _step = 1;

public:

	////		Constructor		////
	Sequence(const int& start = 0, const int& step = 1);

	////		Method		////
	int next();
};

