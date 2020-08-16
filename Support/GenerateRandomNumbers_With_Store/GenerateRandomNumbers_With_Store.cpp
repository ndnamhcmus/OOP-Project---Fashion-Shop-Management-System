#include "GenerateRandomNumbers_With_Store.h"

void State::clear()
{
	this->_a.clear();
}

void State::push_back(const int& number)
{
	this->_a.push_back(number);
}

string State::toString(string separator)
{
	stringstream writer;
	for (auto it = _a.begin(); it != _a.end(); it++)
	{
		writer << *it << separator;
	}
	return writer.str();
}

void Store::generateRandomNumbers(int n, const int& max)
{
	/*n = _rng.next(10, 20);*/
	for (int i = 0; i < n; i++)
	{
		_state.push_back(_rng.next(0, max));
	}
}

void Store::showCurrentNumbers()
{
	cout << _state.toString();
}

void Store::getNumbersFromKeyboard(string type_input)
{
	_state.clear();
	while (true)
	{
		cout << "We have: " << _state._a.size() << " numbers" << endl;
		cout << "Choose:\n";
		cout << "1. Input new number\n";
		cout << "0. Cancel\n";


		int choice;
		cin >> choice;

		if (choice == 1 && type_input == "string")
		{
			cin.ignore();
			string number;
			cout << "Input: ";
			getline(cin, number);


			vector <string> temp = Tokenizer::parse(number, " ");
			for (int i = 0; i < temp.size(); i++)
			{
				_state.push_back(stoi(temp[i]));
			}
		}
		else
		{
			if (choice == 1)
			{
				int number;
				cout << "Input: ";
				cin >> number;
				_state.push_back(number);
			}
			else if (!choice)
			{
				break;
			}
		}
	}
}
