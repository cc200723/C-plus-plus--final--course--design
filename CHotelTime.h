#pragma once
#include "pch.h"
class CHotelTime
{
public:
	CHotelTime();
	CHotelTime(string time);//xxxx-xx-xx格式时间
	CHotelTime(string year, string mouth, string day);
	~CHotelTime();

	string GetTime() const;

    CHotelTime& operator=(const CHotelTime& another)//重载等号
    {
        // 1.防止自身赋值
        if (this == &another)
        {
            return *this;
        }

        this->_year = another._year;
        this->_mouth = another._mouth;
        this->_day = another._day;
        return *this;
    }
private:
	string _year;
	string _mouth;
	string _day;
};

