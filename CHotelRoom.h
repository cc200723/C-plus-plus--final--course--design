#pragma once
#include "pch.h"

class CHotelRoom
{
public:
	//重载构造函数
	CHotelRoom(string roomNumber, string roomType, string roomStatu);
	~CHotelRoom();
	
	//成员变量的get set方法
	string GetRoomNumber();
	void SetRoomNumber(string roomNumber);
	string GetRoomType();
	void SetRoomType(string roomType);
	string GetRoomStatu();
	void SetRoomStatu(string roomStatu);
	
	//重载输出
	friend ostream& operator<<(ostream& os, const CHotelRoom& c)
	{
		cout << setw(12) << c._roomNumber << setw(10) << c._roomType << setw(10) <<
			c._roomStatu << "\n";
		return os;
	}
private:
	string _roomNumber; //房间号
	string _roomType;//房间类型
	string _roomStatu;//房间状态
};

