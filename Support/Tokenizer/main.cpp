#include "Tokenizer.h"
using namespace std;

int main()
{
	//string str = "hello w w w w w";
	//string str = "hello world war 3";


	//vector <string> tokens = Tokenizer::parse(str, " w");
	//cout << "size: " << tokens.size() << endl;
	//for (int i = 0; i < tokens.size(); i++)
	//{
	//	cout << tokens[i] << "\t";
	//}


	string num = "12 14 46 27 3 1 90";
	vector <string> tokens = Tokenizer::parse(num, " ");
	vector <string> temp;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Calculate sum of value: " << Business::Calculate_Sum_Of_Value_In_String(tokens) << endl;
		break;

	case 2:
		cout << "Min value: " << Business::Find_Min_Numeric_Value(tokens) << endl;
		break;

	case 3:
		cout << "Three biggest number: ";
		temp = Business::Find_Three_Biggest_Num(tokens);
		for (int i = 0; i < temp.size(); i++)
		{
			cout << temp[i] << "\t";
		}
		break;

	case 4:
		cout << "Calculate average value: " << Business::Calculate_Average_Value(tokens) << endl;
		break;

	case 5:
		temp = Business::Find_Prime_Number(tokens);
		cout << "Prime number: ";
		for (int i = 0; i < temp.size(); i++)
		{
			cout << temp[i] << "\t";
		}
		break;
	default:
		break;
	}


	system("pause");
	return 0;
}