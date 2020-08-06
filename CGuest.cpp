#include "CGuest.h"

CGuest::CGuest(string idCard, string name, string gender, string roomNumber,
	CHotelTime _registerTime, CHotelTime _checkOutTime):
	_idCard(idCard), _name(name), _gender(gender), _roomNumber(roomNumber),
	_registerTime(_registerTime), _checkOutTime(_checkOutTime)
{
}

CGuest::~CGuest()
{
}

string CGuest::GetIdCard()
{
	return _idCard;
}

void CGuest::SetIdCard(string idCard)
{
	_idCard = idCard;
}

string CGuest::GetName()
{
	return _name;
}

void CGuest::SetName(string name)
{
	_name = name;
}

void CGuest::SetGender(string gender)
{
	_gender = gender;
}

string CGuest::GetRoomNumber()
{
	return _roomNumber;
}

void CGuest::SetRoomNumber(string roomNumber)
{
	_roomNumber = roomNumber;
}

void CGuest::SetCheckOutTime(CHotelTime time)
{
	_checkOutTime = time;
}

string CGuest::GetRegisterTime()
{
	return _registerTime.GetTime();
}

string CGuest::GetCheckOutTime()
{
	return _checkOutTime.GetTime();
}

string CGuest::GetGender()
{
	return _gender;
}
