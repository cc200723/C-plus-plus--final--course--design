#pragma once
#include "CGuest.h"
#include "CHotelRoom.h"

class CManage
{
public:
	CManage();
	~CManage();

	void Run();
	void Load();
	void Save();
	void Menu();
	void ReturnMenu();


	void RegisterRoom();//ס���Ǽ�
	void CheckOutRoom();//�˷��Ǽ�
	void AddRoom();     //��������
	void Query();
	void Alert();//�޸�
	void Delete();

	void AddGuest(string idCard, string name, string gender, 
					string roomNumber, CHotelTime registerTime, CHotelTime checkoutTime);
	void AddHotelRoom(string roomNumeber, string roomType, string roomStatu);

	

private:
	vector<CGuest> _guests;
	vector<CHotelRoom> _hotelRooms;

	string _guests_head;//��ӡ������Ϣͷ
	string _rooms_head;//��ӡ������Ϣͷ
};

