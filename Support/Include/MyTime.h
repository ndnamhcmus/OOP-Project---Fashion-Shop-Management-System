#ifndef _MY_TIME_
#define _MY_TIME_


#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
#include <Tokenizer.h>


using namespace std;

class MyTime
{
private:
	int _hour;
	int _minute;
	int _second;

public:
	MyTime(int hour = 0, int minute = 0, int second = 0);


	////		Methods		////
	string toString();

	static MyTime parse(const string& time);

	static bool tryParse(const string& s_time = "", MyTime time = MyTime(0, 0, 0));

	static bool isValid(const string& time);

	string AmPmMode();


	////		Operators		////
	friend ostream& operator<<(ostream& out, const MyTime& time);

	bool operator>(MyTime time);

	bool operator==(MyTime time);

	bool operator!=(MyTime time);

	bool operator<(MyTime time);

	bool operator>=(MyTime time);

	MyTime& operator=(const int& time);

	MyTime& operator=(const MyTime& time);
};


#endif // !_MY_TIME