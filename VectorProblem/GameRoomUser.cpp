#include "GameRoomUser.h"
#include <iostream>

GameRoomUser::GameRoomUser()
{
}

GameRoomUser::~GameRoomUser()
{
}

bool GameRoomUser::AddUser(UserInfo& userInfo)
{
    // ����� ����� �������, ����� �߰� �� ���� �̸� ����
    if (users.empty())
    {
        users.emplace_back(userInfo);
        masterUserName = userInfo.userName;
        return true;
    }

    if (users.size() < maxSize)
    {
        users.emplace_back(userInfo);
        return true;
    }

    std::cout << "Error: ���� ��� ���� á���ϴ�.\n";
    return false;
}

bool GameRoomUser::DeleteUser(const char* userName)
{
    auto iterator = users.begin();
    for (; iterator != users.end(); ++iterator)
    {
        if (iterator->userName == userName)
        {
            break;
        }
    }

    if (iterator == users.end())
    {
        std::cout << "Error: �����Ϸ��� ������ ã�� ���߽��ϴ�.\n";
        return false;
    }

    if (iterator == users.begin() && users.size() > 1)
    {

    }

    users.erase(iterator);
    if (iterator == users.begin())
    {
        users.erase(iterator);
        masterUserName = users[0].userName;
    }

    return true;
}

bool GameRoomUser::IsEmpty()
{
    return users.empty();
}

bool GameRoomUser::IsFull()
{
    return users.size() == maxSize;
}

UserInfo& GameRoomUser::GetUserOfName(const char* userName)
{


}

UserInfo& GameRoomUser::GetMasterUser()
{


}

UserInfo& GameRoomUser::GetUserOfLastOrder()
{


}

bool GameRoomUser::BanUser(int orderNum)
{

    return false;
}

void GameRoomUser::Clear()
{
    users.clear();
}
