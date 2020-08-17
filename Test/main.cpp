#include <iostream>
#include <vector>
#include <exception>
#include <fstream>
using namespace std;

int main()
{
	int n = 0;
	fstream file;
	file.open("something.txt", ios::in);

	try
	{
		if (!file)
		{
			throw string("abvc");
		}
	}
	catch (const string& error)
	{
		cout << error;
		exit(EXIT_FAILURE);
	}
}