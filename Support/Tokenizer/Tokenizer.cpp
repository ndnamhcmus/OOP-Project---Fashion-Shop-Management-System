#ifndef _TOKENIZER_SOURCE_
#define _TOKENIZER_SOURCE_
#include "Tokenizer.h"


vector <string> Tokenizer::parse(const string& haystack, const string& needle)
{
	vector <string> tokens;
	int start_position = 0;
	int found_position;


	while(true)
	{

		found_position = haystack.find(needle, start_position);
		tokens.push_back(haystack.substr(start_position, found_position - start_position));
		start_position = found_position + needle.size();	// new find position
		if (tokens.at(tokens.size() - 1) == "")
		{
			tokens.pop_back();
		}


		if (found_position == string::npos)
		{
			break;
		}
	}
	return tokens;
}

//////////////////////////////////////////////////////////////////////////////////////////

int Business::Find_Min_Numeric_Value(vector <string> tokens)
{
	int min = stoi(tokens[0]);


	for (int i = 1; i < tokens.size(); i++)
	{
		if (min > stoi(tokens[i]))
		{
			min = stoi(tokens[i]);
		}
	}


	return min;
}

vector <string> Business::Find_Three_Biggest_Num(vector <string> tokens)
{
	////interchange sort////
	for (int i = 0; i < tokens.size() - 1; i++)
	{
		for (int j = i + 1; j < tokens.size(); j++)
		{
			if (stoi(tokens[i]) < stoi(tokens[j]))
			{
				swap(tokens[i], tokens[j]);
			}
		}
	}


	vector <string> temp;
	for (int i = 0; i < 3; i++)
	{
		temp.push_back(tokens[i]);
	}
	return temp;
}

int Business::Calculate_Sum_Of_Value_In_String(const vector <string>& tokens)
{
	int sum = 0;
	for (int i = 0; i < tokens.size(); i++)
	{
		sum = sum + stoi(tokens[i]);
	}
	return sum;
}

double Business::Calculate_Average_Value(const vector <string>& tokens)
{
	return double(Calculate_Sum_Of_Value_In_String(tokens)) / tokens.size();
}

bool Business::is_prime_num(const int& num)
{
	if (num <= 1)
	{
		return false;
	}
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (!(num % i))
		{
			return false;
		}
	}
	return true;
}

vector <string> Business::Find_Prime_Number(const vector <string>& tokens)
{
	vector <string> temp;


	for (int i = 0; i < tokens.size(); i++)
	{
		if (is_prime_num(stoi(tokens[i])))
		{
			temp.push_back(tokens[i]);
		}
	}
	return temp;
}


#endif // !_TOKENIZER_SOURCE_