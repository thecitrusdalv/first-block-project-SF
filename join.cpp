//join.cpp

#include "join.h"

void join(User& user, Room& room)
{
	if(user.roomPtr) {
		if (user.roomPtr == &room)
			return;
		else {
			std::vector<User*> &userVecPtr = user.roomPtr.userVecPtr;
			for (size_t i = 0; i < userVecPtr.size(); i++) {
			if (userVecPtr[i] == &user)
				userVecPtr.erase(userVecPtr.begin()+i);
			}
		}
	}
	user.roomPtr = &room;
	else

	room.usersInRoom.push_back(&user);
}

