//join.cpp

#include "join.h"

void join(User& user, Room& room)
{
	if (user.roomPtr == &room)
		return;

	if (user.roomPtr) {

		std::vector<User*> &oldVec = (*(user.roomPtr)).usersInRoom;

		for (size_t i = 0; i < oldVec.size(); i++) {
			if (oldVec[i] == &user) {
				oldVec.erase(oldVec.begin() + i);
				break;
			}
		}
	}

	user.roomPtr = &room;
	room.usersInRoom.push_back(&user);
}
