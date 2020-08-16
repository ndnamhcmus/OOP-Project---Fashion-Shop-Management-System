#include <iostream>
#include <Random.h>
#include <Tokenizer.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class State
{
private:

	vector <int> _a;

	void clear();

	void push_back(const int& number);

	friend class Store;	


public:

	string toString(string separator = " ");


};

class Store
{
private:

	State _state;
	Random _rng;

public:

	void generateRandomNumbers(int n = 10, const int& max = 999);

	void showCurrentNumbers();

	void getNumbersFromKeyboard(string type_input = "");
};

