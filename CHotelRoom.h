#pragma once
#include "pch.h"

class CHotelRoom
{
public:
	//���ع��캯��
	CHotelRoom(string roomNumber, string roomType, string roomStatu);
	~CHotelRoom();
	
	//��Ա������get set����
	string GetRoomNumber();
	void SetRoomNumber(string roomNumber);
	string GetRoomType();
	void SetRoomType(string roomType);
	string GetRoomStatu();
	void SetRoomStatu(string roomStatu);
	
	//�������
	friend ostream& operator<<(ostream& os, const CHotelRoom& c)
	{
		cout << setw(12) << c._roomNumber << setw(10) << c._roomType << setw(10) <<
			c._roomStatu << "\n";
		return os;
	}
private:
	string _roomNumber; //�����
	string _roomType;//��������
	string _roomStatu;//����״̬
};

