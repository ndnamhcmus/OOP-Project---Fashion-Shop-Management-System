#ifndef _TOKENIZER_
#define _TOKENIZER_


#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;


class Tokenizer
{
public:

	static vector <string> parse(const string& haystack, const string& separator);
	
};

class Business
{
private:

	static bool is_prime_num(const int& num);

public:

	static int Find_Min_Numeric_Value(vector <string> tokens);

	static vector<string> Find_Three_Biggest_Num(vector <string> tokens);

	static int Calculate_Sum_Of_Value_In_String(const vector <string>& tokens);

	static double Calculate_Average_Value(const vector <string>& tokens);

	static vector <string> Find_Prime_Number(const vector <string>& tokens);
};


#endif // !_TOKENIZER_