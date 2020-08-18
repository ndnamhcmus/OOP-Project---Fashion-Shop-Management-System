#ifndef _MEMBERSHIP_LEVEL_
#define _MEMBERSHIP_LEVEL_


#include <iostream>
#include <string>

using namespace std;

class MembershipLevel
{
private:

	string _level;
	static int _cumulative_points;

public:




	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;

	friend class Account;
};


#endif // !_MEMBERSHIP_LEVEL_