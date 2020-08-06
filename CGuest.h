#pragma once
#include "pch.h"
#include "CHotelTime.h"
class CGuest
{
public:
	CGuest(string idCard, string name, string gender, string _roomNumber,
	CHotelTime _registerTime, CHotelTime _checkOutTime);

	~CGuest();

	string GetIdCard();//���֤��
	void SetIdCard(string idCard);
	string GetName();
	void SetName(string name);
	string GetGender();
	void SetGender(string gender);
	string GetRoomNumber();
	void SetRoomNumber(string roomNumber);
	string GetRegisterTime();//��סʱ��
	string GetCheckOutTime();//�˷�ʱ��
	void SetCheckOutTime(CHotelTime time);

	//�������
	friend ostream& operator<<(ostream& os, const CGuest& c)
	{
		cout.left;
		cout << setw(12) << c._idCard << setw(12) << c._name << setw(5) <<
			c._gender << setw(12) << c._roomNumber << setw(12) <<
			c._registerTime.GetTime() << setw(12) << c._checkOutTime.GetTime() << "\n";
		return os;
	}

private:
	string _idCard;//���֤��
	string _name;
	string _gender;
	string _roomNumber;//�ⷿ���
	CHotelTime _registerTime;//��סʱ��
	CHotelTime _checkOutTime;//�˷�ʱ��

};

