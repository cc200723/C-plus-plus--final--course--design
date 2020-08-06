#pragma once
#include "pch.h"
class CHotelTime
{
public:
	CHotelTime();
	CHotelTime(string time);//xxxx-xx-xx��ʽʱ��
	CHotelTime(string year, string mouth, string day);
	~CHotelTime();

	string GetTime() const;

    CHotelTime& operator=(const CHotelTime& another)//���صȺ�
    {
        // 1.��ֹ����ֵ
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

