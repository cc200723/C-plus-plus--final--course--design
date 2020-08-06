#include "CHotelTime.h"

CHotelTime::CHotelTime():
	_year("-"), _mouth(""), _day("")
{
}

CHotelTime::CHotelTime(string time)
{
	_year = time.substr(0, 4);
	_mouth = time.substr(5, 2);
	_day = time.substr(8, 2);
}

CHotelTime::CHotelTime(string year, string mouth, string day):
	_year(year), _mouth(mouth), _day(day)
{
}

CHotelTime::~CHotelTime()
{
}

string CHotelTime::GetTime() const
{
	return _year + '-' + _mouth + '-' + _day;
}
