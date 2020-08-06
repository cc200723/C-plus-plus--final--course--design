#include "CManage.h"

#include "CManage.h"


void CManage::Menu()
{
    system("cls");//清屏
    std::cout << "**************************************************\n";
    std::cout << "*------------------酒店房间管理系统---------------*\n";
    std::cout << "*------        1            住房登记       ------*\n";
    std::cout << "*------        2            退房登记       ------*\n";
    std::cout << "*------        3            新增房间       ------*\n";
    std::cout << "*------        4            查    询       ------*\n";
    std::cout << "*------        5            删    除       ------*\n";
    std::cout << "*------        6            修    改       ------*\n";
    std::cout << "*------        7            保    存       ------*\n";
    std::cout << "*------        8            退    出       ------*\n";
    std::cout << "**************************************************\n";

}

void CManage::ReturnMenu()
{
    cout << "按任意键返回主菜单......\n";
    getchar();
    getchar();
    Menu();
}

void CManage::RegisterRoom()
{
    string roomNumber;
    string idCard;//身份证号
    string name;
    string gender;
    string registerTime;//入住时间
    //CHotelTime checkOutTime;//退房时间
    system("cls");
    cout << "请输入房间编号:";
    cin >> roomNumber;
    int i;
    for (i = 0; i < _hotelRooms.size(); i++)
    {
        if (_hotelRooms[i].GetRoomNumber() == roomNumber)
        {
            break;
        }
    }
    if (i == _hotelRooms.size() || _hotelRooms[i].GetRoomStatu() != "空闲")
    {
        cout << "无该房间或该房间已被占用\n";
        ReturnMenu();
        return;
    }
    else
    {
        _hotelRooms[i].SetRoomStatu("占用");
    }

    cout << "请输入住客身份证信息:";
    cin >> idCard;
    cout << "请输入住客姓名:";
    cin >> name;
    cout << "请输入住客性别:";
    cin >> gender;
    cout << "请输入租客入住时间(xxxx-xx-xx):";
    cin >> registerTime;
    CHotelTime time(registerTime);
    CHotelTime check_out_time;//此时为空
    AddGuest(idCard, name, gender, roomNumber, time, check_out_time);
    cout << "房间订单生成!!!\n";
    ReturnMenu();
}

void CManage::CheckOutRoom()
{
    system("cls");
    string roomNumber;
    cout << "请输入房间编号:";
    cin >> roomNumber;
    int i;
    for (i = 0; i < _hotelRooms.size(); i++)
    {
        if (_hotelRooms[i].GetRoomNumber() == roomNumber)
        {
            break;
        }
    }
    if (i == _hotelRooms.size() || _hotelRooms[i].GetRoomStatu() == "空闲")
    {
        cout << "没有该房间的使用情况，请核准后再退房!!!\n";
        ReturnMenu();
        return;
    }
    else
    {
        _hotelRooms[i].SetRoomStatu("空闲");
    }

    string check_out_time;
    cout << "请输入退租时间(xxxx-xx-xx):";
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
   
    cout << "房间退租成功!!!\n";
    ReturnMenu();
}

void CManage::AddRoom()
{
    string roomNumber; //房间号
    string roomType;//房间类型
    string roomStatu;//房间状态
    system("cls");
    cout << "请输入新增房间编号:";
    cin >> roomNumber;

    int i;
    for (i = 0; i < _hotelRooms.size(); i++)
    {
        if (_hotelRooms[i].GetRoomNumber() == roomNumber)
        {
            cout << "当前房间已存在!!!\n";
            ReturnMenu();
            return;
        }
    }

    cout << "请输入新增房间类型(大、中、小):";
    cin >> roomType;
    
    AddHotelRoom(roomNumber, roomType, "空闲");
    cout << "新增房间成功!!!\n";
    ReturnMenu();
}


CManage::CManage()
{
    _guests_head = "     身份证号     姓名   性别      房号     入住时间       退房时间\n";
    _rooms_head = "       房间号    房间类型   状态\n";
}

CManage::~CManage()
{
}

void CManage::Run()
{
    Menu();
    char op;
    cout << "请输入菜单选项:";

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
        cout << "请输入菜单选项:";
    }
}

void CManage::Load()//文件读取
{
    int flag = 0;
    //录入顾客信息
    string guestInfoPathName = "guest.txt";
    ifstream in_guestInfo(guestInfoPathName);
    string line;
    if (!in_guestInfo.is_open())
    {
        cout << "顾客文件加载失败,稍后将重新生成！！！\n";
        
    }
    else {

        while (getline(in_guestInfo, line))
        {
            if (flag == 0)
            {
                flag = 1;//首行跳过
                continue;
            }
            string info_guest[4];
            string info_time[6];
            int n = line.size();
            int j = 0, k = 0;;
            for (int i = 0; i < n; i++)//文本以空格隔开
            {
                if (line[i] != ' ' && line[i] != '\0')
                {

                    if (j < 4)
                    {
                        info_guest[j] += line[i];
                    }
                    else//时间 年月日处理
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
                    if (line[i - 1] != ' ')//防止对于空格
                        j++;
                }
            }

            CHotelTime register_time(info_time[0], info_time[1], info_time[2]);
            CHotelTime check_out_time(info_time[3], info_time[4], info_time[5]);
            AddGuest(info_guest[0], info_guest[1], info_guest[2], info_guest[3],
                register_time, check_out_time);
        }
        in_guestInfo.close();
        cout << "顾客数据加载成功！！！\n";
    }
   

    flag = 0;
    //录入客房信息
    string roomInfoPathName = "room.txt";
    ifstream in_roomInfo(roomInfoPathName);

    if (!in_roomInfo.is_open())
    {
        cout << "房间信息文件加载失败, 稍后将重新生成！！！\n";
        cout << "任意键跳转到菜单...";
        getchar();
        return;
    }

    while (getline(in_roomInfo, line))
    {
        if (flag == 0)//跳过第一行
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

    cout << "房间数据加载成功！！！\n";
    cout << "任意键跳转到菜单...";
    getchar();
}


void CManage::Query()
{
    system("cls");
    cout << "输入A显示顾客信息， 输入B显示房间信息:";
    char ch;
    cin >> ch;
    if (ch == 'A' || ch == 'a')
    {
        cout << "--------------顾客信息----------------------\n";
        cout << _guests_head;
        for (int i = 0; i < _guests.size(); i++)
        {
            cout << _guests[i];
        }
        cout << "--------------------------------------------\n";
    }
    else if (ch == 'B' || ch == 'b')
    {
        cout << "--------------房间信息-----------------\n";
        cout << _rooms_head;
        for (int i = 0; i < _hotelRooms.size(); i++)
        {
            cout << _hotelRooms[i];
        }
        cout << "--------------------------------------\n";
    }
    cout << "查询成功!!!\n";
    ReturnMenu();
}

void CManage::Alert()
{
    system("cls");
    cout << "输入1修改顾客信息，输入2修改房间信息:";
    int op, loc;
    string info;
    cin >> op;
    if (op == 1)//修改顾客信息
    {
        cout << "请输入需要修改的顾客信息(身份证/姓名):";
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
            cout << "无该顾客信息，请核实后再行修改!!!\n";
            ReturnMenu();
            return;
        }
        cout << "请选择需要修改的顾客信息内容(1姓名2性别3房间号)";
        cin >> op;
        if (op == 1)
        {
            cout << "请输入修改后的姓名:";
            cin >> info;
            _guests[loc].SetName(info);
        }
        else if (op == 2)
        {
            cout << "请输入修改后的性别:";
            cin >> info;
            _guests[loc].SetGender(info);
        }
        else if (op == 3)
        {
            cout << "请输入修改后的房间号:";
            cin >> info;
            int loc_room;
            for (loc_room = 0; loc_room < _hotelRooms.size(); loc_room++)
            {
                if (_hotelRooms[loc_room].GetRoomNumber() == info)
                {
                    break;
                }
            }

            if (loc_room == _hotelRooms.size() || _hotelRooms[loc_room].GetRoomStatu() != "空闲")
            {
                cout << "该房间不存在或已被占用，无法更改房间!!!\n";
                ReturnMenu();
                return;
            }
            _hotelRooms[loc_room].SetRoomStatu("占用");
            for (int i = 0; i < _hotelRooms.size(); i++)//释放原来被占用房间
            {
                if (_guests[loc].GetRoomNumber() == _hotelRooms[i].GetRoomNumber())
                {
                    _hotelRooms[i].SetRoomStatu("空闲");
                    break;
                }
            }
            _guests[loc].SetRoomNumber(info);
        }
        else
        {
            cout << "输入选项错误！！!\n";
            ReturnMenu();
            return;
        }
    }
    else if (op == 2)//修改房间信息
    {
        string room_number;
        cout << "请输入修改的房间编号:";
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
            cout << "输入房间编号错误错误！！!\n";
            ReturnMenu();
            return;
        }
        cout << "请输入修改后的房间类型:";
        cin >> info;
        _hotelRooms[loc].SetRoomType(info);
    }
    cout << "修改成功！！!\n";
    ReturnMenu();
}


void CManage::Delete()
{
    system("cls");
    char ch;
    cout << "输入A删除顾客信息， 输入B删除房间信息:";
    cin >> ch;
    if (ch == 'A' || ch == 'a')
    {
        cout << "请输入顾客信息（姓名、身份证号）:";
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
                        _hotelRooms[j].SetRoomStatu("空闲"); break;
                    }
                }
                _guests.erase(_guests.begin() + i);
                cout << "删除成功!!!\n";
                ReturnMenu();
                return;
            }
        }
        cout << "无该顾客信息，请核实后删除!!!\n";
        ReturnMenu();
        return;
    }
    else if (ch == 'B' || ch == 'b')
    {
        cout << "请输入房间编号:";
        string info;
        cin >> info;
        for (int i = 0; i < _hotelRooms.size(); i++)
        {
            if (_hotelRooms[i].GetRoomNumber() == info && 
                _hotelRooms[i].GetRoomStatu() == "空闲")
            {
                _hotelRooms.erase(_hotelRooms.begin() + i);
                cout << "删除成功!!!\n";
                ReturnMenu();
                return;
            }
        }
        cout << "无此房间信息或该房间非空闲状态，请核实后删除!!!\n";
        ReturnMenu();
        return;

    }
    else
    {
        cout << "输入代码有误，请重新输入！！！\n";
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
    //保存顾客信息
    string guestInfoPathName = "guest.txt";
    std::ofstream guestInfoPath(guestInfoPathName, std::ios::out);
    if (!guestInfoPath)
    {
        cout << "保存顾客信息失败!!!";
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


    //保存房间信息
    string roomInfoPathName = "room.txt";
    std::ofstream roomInfoPath(roomInfoPathName, std::ios::out);
    if (!roomInfoPath)
    {
        cout << "保存顾客信息失败!!!";
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

    cout << "信息保存成功!!!\n";
    getchar();

}

