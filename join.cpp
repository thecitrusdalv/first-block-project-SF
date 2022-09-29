//join.cpp

#include "join.h"

void join(User& user, Room& room)
{
	user.roomPtr = &room;
	room.usersInRoom.push_back(&user);
}

