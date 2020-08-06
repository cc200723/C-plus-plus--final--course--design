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


	void RegisterRoom();//住房登记
	void CheckOutRoom();//退房登记
	void AddRoom();     //新增房间
	void Query();
	void Alert();//修改
	void Delete();

	void AddGuest(string idCard, string name, string gender, 
					string roomNumber, CHotelTime registerTime, CHotelTime checkoutTime);
	void AddHotelRoom(string roomNumeber, string roomType, string roomStatu);

	

private:
	vector<CGuest> _guests;
	vector<CHotelRoom> _hotelRooms;

	string _guests_head;//打印宾客信息头
	string _rooms_head;//打印房间信息头
};

