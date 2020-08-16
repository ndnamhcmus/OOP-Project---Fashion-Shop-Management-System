#include "Clock.h"

Time::Time(int hour, int minute, int second)
{
	if (!hour && !minute && !second)
	{
		time_t info = time(0);
		tm* time_now = new tm;


		localtime_s(time_now, &info);


		hour = time_now->tm_hour;
		minute = time_now->tm_min;
		second - time_now->tm_sec;
		delete time_now;
	}
	this->_hour = hour;
	this->_minute = minute;
	this->_second = second;
}

string Time::toString()
{
	string s_hour = to_string(_hour);
	string s_minute = to_string(_minute);
	string s_second = to_string(_second);


	if (s_hour.length() < 2)
	{
		s_hour.insert(0, "0");
	}
	if (s_minute.length() < 2)
	{
		s_minute.insert(0, "0");
	}
	if (s_second.length() < 2)
	{
		s_second.insert(0, "0");
	}


	stringstream writer;
	writer << s_hour << ":" << s_minute << ":" << s_second;
	return writer.str();
}

Time Time::parse(const string& time)
{
	vector <string> temp = Tokenizer::parse(time, ":");
	return Time(stoi(temp[0]), stoi(temp[1]), stoi(temp[2]));
}

bool Time::tryParse(const string& s_time, Time time)
{
	if (s_time != "")
	{
		vector <string> temp = Tokenizer::parse(s_time, ":");
		if (temp.size() != 3)
		{
			return false;
		}
	}
	if (time != Time())
	{
		vector <string> temp = Tokenizer::parse(time.toString(), ":");
		if (temp.size() != 3)
		{
			return false;
		}
	}


	return true;
}

bool Time::isValid(const string& time)
{
	////		kiểm tra form		////
	for (int i = 0; i < time.length(); i++)
	{
		if ((i + 1) % 3)
		{
			if (time[i] < '0' || time[i] > '9')
			{
				return false;
			}
		}
		else
		{
			if (time[i] != ':')
			{
				return false;
			}
		}
	}


	////		kiểm tra nhập đúng giới hạn		////
	Time time_to_check = parse(time);
	if (time_to_check._hour < 0 || time_to_check._hour > 24)
	{
		return false;
	}
	if (time_to_check._minute < 0 || time_to_check._minute > 59)
	{
		return false;
	}
	if (time_to_check._second < 0 || time_to_check._second > 59)
	{
		return false;
	}
	return true;
}

bool Time::operator>(Time time)
{
	if (this->_hour > time._hour)
	{
		return true;
	}
	else if (this->_hour == time._hour)
	{
		if (this->_minute > time._minute)
		{
			return true;
		}
		else if (this->_minute == time._minute)
		{
			if (this->_second > time._second)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

bool Time::operator==(Time time)
{
	if (this->_hour == time._hour && this->_minute == time._minute && this->_second == time._second)
	{
		return true;
	}
	return false;
}

bool Time::operator!=(Time time)
{
	if (*this == time)
	{
		return false;
	}
	return true;
}

bool Time::operator<(Time time)
{
	if (!((*this > time) && (*this == time)))
	{
		return true;
	}
	return false;
}

bool Time::operator>=(Time time)
{
	if (*this > time || *this == time)
	{
		return true;
	}
	return false;
}

Time& Time::operator=(const int& num)
{
	this->_hour = num;
	this->_minute = num;
	this->_second = num;


	return *this;
}

ostream& operator<<(ostream& out, const Time& time)
{
	out << time._hour << ":" << time._minute << ":" << time._second;
	return out;
}

string Time::AmPmMode()
{
	stringstream writer;


	Time temp = *this;
	if (temp >= Time(13, 0, 0))
	{
		if (temp >= Time(24, 0, 0))
		{
			temp._hour = 0;
			writer << temp.toString() << " am";
			return writer.str();
		}


		temp._hour = temp._hour - 12;
		writer << temp.toString() << " pm";
		return writer.str();
	}
	else
	{
		if (temp >= Time(12, 0, 0))
		{
			writer << temp.toString() << " pm";
			return writer.str();
		}


		writer << temp.toString() << " am";
		return writer.str();
	}
}
