#include "CHotelRoom.h"

CHotelRoom::CHotelRoom(string roomNumber, string roomType, string roomStatu):
	_roomNumber(roomNumber), _roomType(roomType), _roomStatu(roomStatu)
{
}

CHotelRoom::~CHotelRoom()
{
}

string CHotelRoom::GetRoomNumber()
{
	return _roomNumber;
}

void CHotelRoom::SetRoomNumber(string roomNumber)
{
	_roomNumber = roomNumber;
}

string CHotelRoom::GetRoomType()
{
	return _roomType;
}

void CHotelRoom::SetRoomType(string roomType)
{
	_roomType = roomType;
}

string CHotelRoom::GetRoomStatu()
{
	return _roomStatu;
}

void CHotelRoom::SetRoomStatu(string roomStatu)
{
	_roomStatu = roomStatu;
}
