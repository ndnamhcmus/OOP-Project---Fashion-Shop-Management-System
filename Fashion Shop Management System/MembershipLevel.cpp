#include "MembershipLevel.h"

//int MembershipLevel::_cumulative_points;

MembershipLevel::MembershipLevel(string level, int cumulative_points)
{
		_level = level;
		_cumulative_points = cumulative_points;
}

void MembershipLevel::setLevel(string level)
{
	_level = level;
}

string MembershipLevel::getLevel()
{
	return _level;
}

void MembershipLevel::setCumulativePoints(int cp)
{
	_cumulative_points = cp;
}

int MembershipLevel::getCummulativePoints()
{
	return _cumulative_points;
}

void MembershipLevel::increaseCumulativePoints()
{
	++_cumulative_points;
}

double MembershipLevel::getDiscount(string _level)
{
	if (_level == "Gold") return 0.1;
	else if (_level == "Silver") return 0.05;
	else if (_level == "Bronze") return 0.03;
	return 0.0;
}

void MembershipLevel::updateLevel()
{
	if (_cumulative_points >= 100) {
		setLevel("Gold");
		return;
	}
	else if (_cumulative_points >= 50) {
		setLevel("Silver");
		return;
	}
	else if (_cumulative_points >= 30) {
		setLevel("Bronze");
		return;
	}
	else
	{
		setLevel("none");
		return;
	}
}
