#pragma once
#include "pch.h"
#include "CHotelTime.h"
class CGuest
{
public:
	CGuest(string idCard, string name, string gender, string _roomNumber,
	CHotelTime _registerTime, CHotelTime _checkOutTime);

	~CGuest();

	string GetIdCard();//身份证号
	void SetIdCard(string idCard);
	string GetName();
	void SetName(string name);
	string GetGender();
	void SetGender(string gender);
	string GetRoomNumber();
	void SetRoomNumber(string roomNumber);
	string GetRegisterTime();//入住时间
	string GetCheckOutTime();//退房时间
	void SetCheckOutTime(CHotelTime time);

	//重载输出
	friend ostream& operator<<(ostream& os, const CGuest& c)
	{
		cout.left;
		cout << setw(12) << c._idCard << setw(12) << c._name << setw(5) <<
			c._gender << setw(12) << c._roomNumber << setw(12) <<
			c._registerTime.GetTime() << setw(12) << c._checkOutTime.GetTime() << "\n";
		return os;
	}

private:
	string _idCard;//身份证号
	string _name;
	string _gender;
	string _roomNumber;//租房编号
	CHotelTime _registerTime;//入住时间
	CHotelTime _checkOutTime;//退房时间

};

