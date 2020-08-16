#ifndef _CLOCK_
#define _CLOCK_


#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
#include <Tokenizer.h>


using namespace std;

class Time
{
private:
	int _hour;
	int _minute;
	int _second;

public:
	Time(int hour = 0, int minute = 0, int second = 0);


	////		Methods		////
	string toString();

	static Time parse(const string& time);

	static bool tryParse(const string& s_time = "", Time time = Time(0, 0, 0));

	static bool isValid(const string& time);

	string AmPmMode();


	////		Operators		////
	friend ostream& operator<<(ostream& out, const Time& time);

	bool operator>(Time time);

	bool operator==(Time time);

	bool operator!=(Time time);

	bool operator<(Time time);

	bool operator>=(Time time);

	Time& operator=(const int& time);

};


#endif // !_CLOCK_