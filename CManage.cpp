#include "CManage.h"

#include "CManage.h"


void CManage::Menu()
{
    system("cls");//����
    std::cout << "**************************************************\n";
    std::cout << "*------------------�Ƶ귿�����ϵͳ---------------*\n";
    std::cout << "*------        1            ס���Ǽ�       ------*\n";
    std::cout << "*------        2            �˷��Ǽ�       ------*\n";
    std::cout << "*------        3            ��������       ------*\n";
    std::cout << "*------        4            ��    ѯ       ------*\n";
    std::cout << "*------        5            ɾ    ��       ------*\n";
    std::cout << "*------        6            ��    ��       ------*\n";
    std::cout << "*------        7            ��    ��       ------*\n";
    std::cout << "*------        8            ��    ��       ------*\n";
    std::cout << "**************************************************\n";

}

void CManage::ReturnMenu()
{
    cout << "��������������˵�......\n";
    getchar();
    getchar();
    Menu();
}

void CManage::RegisterRoom()
{
    string roomNumber;
    string idCard;//���֤��
    string name;
    string gender;
    string registerTime;//��סʱ��
    //CHotelTime checkOutTime;//�˷�ʱ��
    system("cls");
    cout << "�����뷿����:";
    cin >> roomNumber;
    int i;
    for (i = 0; i < _hotelRooms.size(); i++)
    {
        if (_hotelRooms[i].GetRoomNumber() == roomNumber)
        {
            break;
        }
    }
    if (i == _hotelRooms.size() || _hotelRooms[i].GetRoomStatu() != "����")
    {
        cout << "�޸÷����÷����ѱ�ռ��\n";
        ReturnMenu();
        return;
    }
    else
    {
        _hotelRooms[i].SetRoomStatu("ռ��");
    }

    cout << "������ס�����֤��Ϣ:";
    cin >> idCard;
    cout << "������ס������:";
    cin >> name;
    cout << "������ס���Ա�:";
    cin >> gender;
    cout << "�����������סʱ��(xxxx-xx-xx):";
    cin >> registerTime;
    CHotelTime time(registerTime);
    CHotelTime check_out_time;//��ʱΪ��
    AddGuest(idCard, name, gender, roomNumber, time, check_out_time);
    cout << "���䶩������!!!\n";
    ReturnMenu();
}

void CManage::CheckOutRoom()
{
    system("cls");
    string roomNumber;
    cout << "�����뷿����:";
    cin >> roomNumber;
    int i;
    for (i = 0; i < _hotelRooms.size(); i++)
    {
        if (_hotelRooms[i].GetRoomNumber() == roomNumber)
        {
            break;
        }
    }
    if (i == _hotelRooms.size() || _hotelRooms[i].GetRoomStatu() == "����")
    {
        cout << "û�и÷����ʹ����������׼�����˷�!!!\n";
        ReturnMenu();
        return;
    }
    else
    {
        _hotelRooms[i].SetRoomStatu("����");
    }

    string check_out_time;
    cout << "����������ʱ��(xxxx-xx-xx):";
    cin >> check_out_time;
    CHotelTime time(check_out_time);
    for (i = 0; i < _guests.size(); i++)
    {
        if (_guests[i].GetRoomNumber() == roomNumber)    
        {
            _guests[i].SetCheckOutTime(time);
            break;
        }
    }
   
    cout << "��������ɹ�!!!\n";
    ReturnMenu();
}

void CManage::AddRoom()
{
    string roomNumber; //�����
    string roomType;//��������
    string roomStatu;//����״̬
    system("cls");
    cout << "����������������:";
    cin >> roomNumber;

    int i;
    for (i = 0; i < _hotelRooms.size(); i++)
    {
        if (_hotelRooms[i].GetRoomNumber() == roomNumber)
        {
            cout << "��ǰ�����Ѵ���!!!\n";
            ReturnMenu();
            return;
        }
    }

    cout << "������������������(���С�С):";
    cin >> roomType;
    
    AddHotelRoom(roomNumber, roomType, "����");
    cout << "��������ɹ�!!!\n";
    ReturnMenu();
}


CManage::CManage()
{
    _guests_head = "     ���֤��     ����   �Ա�      ����     ��סʱ��       �˷�ʱ��\n";
    _rooms_head = "       �����    ��������   ״̬\n";
}

CManage::~CManage()
{
}

void CManage::Run()
{
    Menu();
    char op;
    cout << "������˵�ѡ��:";

    while (op = getchar())
    {
        switch (op)
        {
        case '1':
            RegisterRoom();
            break;
        case '2':
            CheckOutRoom();
            break;
        case '3':
            AddRoom();
            break;
        case '4':
            Query();
            break;
        case '5':
            Delete();
            break;
        case '6':
            Alert();
            break;
        case '7':
            Save();
            break;
        case '8':
            return;
        default:
            break;
        }
        cout << "������˵�ѡ��:";
    }
}

void CManage::Load()//�ļ���ȡ
{
    int flag = 0;
    //¼��˿���Ϣ
    string guestInfoPathName = "guest.txt";
    ifstream in_guestInfo(guestInfoPathName);
    string line;
    if (!in_guestInfo.is_open())
    {
        cout << "�˿��ļ�����ʧ��,�Ժ��������ɣ�����\n";
        
    }
    else {

        while (getline(in_guestInfo, line))
        {
            if (flag == 0)
            {
                flag = 1;//��������
                continue;
            }
            string info_guest[4];
            string info_time[6];
            int n = line.size();
            int j = 0, k = 0;;
            for (int i = 0; i < n; i++)//�ı��Կո����
            {
                if (line[i] != ' ' && line[i] != '\0')
                {

                    if (j < 4)
                    {
                        info_guest[j] += line[i];
                    }
                    else//ʱ�� �����մ���
                    {
                        if (line[i] == '-')
                        {
                            k++; continue;
                        }
                        info_time[k] += line[i];
                    }
                }
                else
                {
                    if (line[i - 1] != ' ')//��ֹ���ڿո�
                        j++;
                }
            }

            CHotelTime register_time(info_time[0], info_time[1], info_time[2]);
            CHotelTime check_out_time(info_time[3], info_time[4], info_time[5]);
            AddGuest(info_guest[0], info_guest[1], info_guest[2], info_guest[3],
                register_time, check_out_time);
        }
        in_guestInfo.close();
        cout << "�˿����ݼ��سɹ�������\n";
    }
   

    flag = 0;
    //¼��ͷ���Ϣ
    string roomInfoPathName = "room.txt";
    ifstream in_roomInfo(roomInfoPathName);

    if (!in_roomInfo.is_open())
    {
        cout << "������Ϣ�ļ�����ʧ��, �Ժ��������ɣ�����\n";
        cout << "�������ת���˵�...";
        getchar();
        return;
    }

    while (getline(in_roomInfo, line))
    {
        if (flag == 0)//������һ��
        {
            flag = 1;
            continue;
        }
        string room_info[3];
        int n = line.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (line[i] != ' ' && line[i] != '\0')
            {
                room_info[j] += line[i];
            }
            else
            {
                if (line[i - 1] != ' ')
                    j++;
            }
        }

        AddHotelRoom(room_info[0], room_info[1], room_info[2]);
    }
    in_roomInfo.close();

    cout << "�������ݼ��سɹ�������\n";
    cout << "�������ת���˵�...";
    getchar();
}


void CManage::Query()
{
    system("cls");
    cout << "����A��ʾ�˿���Ϣ�� ����B��ʾ������Ϣ:";
    char ch;
    cin >> ch;
    if (ch == 'A' || ch == 'a')
    {
        cout << "--------------�˿���Ϣ----------------------\n";
        cout << _guests_head;
        for (int i = 0; i < _guests.size(); i++)
        {
            cout << _guests[i];
        }
        cout << "--------------------------------------------\n";
    }
    else if (ch == 'B' || ch == 'b')
    {
        cout << "--------------������Ϣ-----------------\n";
        cout << _rooms_head;
        for (int i = 0; i < _hotelRooms.size(); i++)
        {
            cout << _hotelRooms[i];
        }
        cout << "--------------------------------------\n";
    }
    cout << "��ѯ�ɹ�!!!\n";
    ReturnMenu();
}

void CManage::Alert()
{
    system("cls");
    cout << "����1�޸Ĺ˿���Ϣ������2�޸ķ�����Ϣ:";
    int op, loc;
    string info;
    cin >> op;
    if (op == 1)//�޸Ĺ˿���Ϣ
    {
        cout << "��������Ҫ�޸ĵĹ˿���Ϣ(���֤/����):";
        cin >> info;
        for (loc = 0; loc < _guests.size(); loc++)
        {
            if (_guests[loc].GetIdCard() == info || _guests[loc].GetName() == info)
            {
                break;
            }
        }

        if (loc == _guests.size())
        {
            cout << "�޸ù˿���Ϣ�����ʵ�������޸�!!!\n";
            ReturnMenu();
            return;
        }
        cout << "��ѡ����Ҫ�޸ĵĹ˿���Ϣ����(1����2�Ա�3�����)";
        cin >> op;
        if (op == 1)
        {
            cout << "�������޸ĺ������:";
            cin >> info;
            _guests[loc].SetName(info);
        }
        else if (op == 2)
        {
            cout << "�������޸ĺ���Ա�:";
            cin >> info;
            _guests[loc].SetGender(info);
        }
        else if (op == 3)
        {
            cout << "�������޸ĺ�ķ����:";
            cin >> info;
            int loc_room;
            for (loc_room = 0; loc_room < _hotelRooms.size(); loc_room++)
            {
                if (_hotelRooms[loc_room].GetRoomNumber() == info)
                {
                    break;
                }
            }

            if (loc_room == _hotelRooms.size() || _hotelRooms[loc_room].GetRoomStatu() != "����")
            {
                cout << "�÷��䲻���ڻ��ѱ�ռ�ã��޷����ķ���!!!\n";
                ReturnMenu();
                return;
            }
            _hotelRooms[loc_room].SetRoomStatu("ռ��");
            for (int i = 0; i < _hotelRooms.size(); i++)//�ͷ�ԭ����ռ�÷���
            {
                if (_guests[loc].GetRoomNumber() == _hotelRooms[i].GetRoomNumber())
                {
                    _hotelRooms[i].SetRoomStatu("����");
                    break;
                }
            }
            _guests[loc].SetRoomNumber(info);
        }
        else
        {
            cout << "����ѡ����󣡣�!\n";
            ReturnMenu();
            return;
        }
    }
    else if (op == 2)//�޸ķ�����Ϣ
    {
        string room_number;
        cout << "�������޸ĵķ�����:";
        cin >> room_number;
        for (loc = 0; loc < _hotelRooms.size(); loc++)
        {
            if (_hotelRooms[loc].GetRoomNumber() == room_number)
            {
                break;
            }
        }
        if (loc == _hotelRooms.size())
        {
            cout << "���뷿���Ŵ�����󣡣�!\n";
            ReturnMenu();
            return;
        }
        cout << "�������޸ĺ�ķ�������:";
        cin >> info;
        _hotelRooms[loc].SetRoomType(info);
    }
    cout << "�޸ĳɹ�����!\n";
    ReturnMenu();
}


void CManage::Delete()
{
    system("cls");
    char ch;
    cout << "����Aɾ���˿���Ϣ�� ����Bɾ��������Ϣ:";
    cin >> ch;
    if (ch == 'A' || ch == 'a')
    {
        cout << "������˿���Ϣ�����������֤�ţ�:";
        string info;
        cin >> info;
        for (int i = 0; i < _guests.size(); i++)
        {
            if (_guests[i].GetName() == info ||
                _guests[i].GetIdCard() == info)
            {
                for (int j = 0; j < _hotelRooms.size(); j++)
                {
                    if (_guests[i].GetRoomNumber() == _hotelRooms[j].GetRoomNumber())
                    {
                        _hotelRooms[j].SetRoomStatu("����"); break;
                    }
                }
                _guests.erase(_guests.begin() + i);
                cout << "ɾ���ɹ�!!!\n";
                ReturnMenu();
                return;
            }
        }
        cout << "�޸ù˿���Ϣ�����ʵ��ɾ��!!!\n";
        ReturnMenu();
        return;
    }
    else if (ch == 'B' || ch == 'b')
    {
        cout << "�����뷿����:";
        string info;
        cin >> info;
        for (int i = 0; i < _hotelRooms.size(); i++)
        {
            if (_hotelRooms[i].GetRoomNumber() == info && 
                _hotelRooms[i].GetRoomStatu() == "����")
            {
                _hotelRooms.erase(_hotelRooms.begin() + i);
                cout << "ɾ���ɹ�!!!\n";
                ReturnMenu();
                return;
            }
        }
        cout << "�޴˷�����Ϣ��÷���ǿ���״̬�����ʵ��ɾ��!!!\n";
        ReturnMenu();
        return;

    }
    else
    {
        cout << "��������������������룡����\n";
        ReturnMenu();
    }
}

void CManage::AddGuest(string idCard, string name, string gender,
         string roomNumber, CHotelTime registerTime, CHotelTime checkoutTime)
{
    CGuest guest(idCard, name, gender, roomNumber, registerTime, checkoutTime);
    _guests.push_back(guest);
}

void CManage::AddHotelRoom(string roomNumber, string roomType, string roomStatu)
{
    CHotelRoom hotelroom(roomNumber, roomType, roomStatu);
    _hotelRooms.push_back(hotelroom);
}


void CManage::Save()
{
    // TODO: Add your control notification handler code here
    //����˿���Ϣ
    string guestInfoPathName = "guest.txt";
    std::ofstream guestInfoPath(guestInfoPathName, std::ios::out);
    if (!guestInfoPath)
    {
        cout << "����˿���Ϣʧ��!!!";
        return;
    }
    guestInfoPath << _guests_head;

    string str;
    for (int i = 0; i < _guests.size(); i++)
    {
        str = _guests[i].GetIdCard() + "        ";
        str += (_guests[i].GetName()) + "           ";
        str += (_guests[i].GetGender()) + "        ";
        str += (_guests[i].GetRoomNumber()) + "        ";
        str += _guests[i].GetRegisterTime() + "        ";
        str += _guests[i].GetCheckOutTime();
        str += "\n";
        guestInfoPath << str;
    }
    guestInfoPath.close();


    //���淿����Ϣ
    string roomInfoPathName = "room.txt";
    std::ofstream roomInfoPath(roomInfoPathName, std::ios::out);
    if (!roomInfoPath)
    {
        cout << "����˿���Ϣʧ��!!!";
        return;
    }
    roomInfoPath << _rooms_head;


    for (int i = 0; i < _hotelRooms.size(); i++)
    {
        str = _hotelRooms[i].GetRoomNumber() + "     ";
        str += (_hotelRooms[i].GetRoomType()) + "       "; 
        str += _hotelRooms[i].GetRoomStatu();
        str += "\n";
        roomInfoPath << str;
    }
    roomInfoPath.close();

    cout << "��Ϣ����ɹ�!!!\n";
    getchar();

}

