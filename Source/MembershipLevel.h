#ifndef _MEMBERSHIP_LEVEL_
#define _MEMBERSHIP_LEVEL_


#include <iostream>
#include <string>

using namespace std;

class MembershipLevel
{
private:

	string _level;
	int _cumulative_points;

public:

	/*~MembershipLevel()
	{
		updateLevel();
	}*/

public:

	MembershipLevel(string level = "", int cumulative_points = 0);

public:

	void setLevel(string);

	void setCumulativePoints(int);

public:

	string getLevel();

	static double getDiscount(string _level);

	int getCummulativePoints();
	void increaseCumulativePoints();

	void updateLevel();

	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;

	friend class Account;
};


#endif // !_MEMBERSHIP_LEVEL_