//join.cpp

#include "join.h"

void join(User& user, Room& room)
{
	//Если юзер и так находится в заданной комнате
	if (user.roomPtr == &room)
		return;

	//Если юзер находился в какой либо комнате
	if (user.roomPtr) {

		//Ссылка на вектор юзеров для удобства
		std::vector<User*> &oldVec = (*(user.roomPtr)).usersInRoom;

		//Поиск юзера в текущей комнате для его удаления из вектора
		for (size_t i = 0; i < oldVec.size(); i++) {
			if (oldVec[i] == &user) {
				oldVec.erase(oldVec.begin() + i);
				break;
			}
		}
	}

	//Связывание юзера с новой комнатой
	user.roomPtr = &room;

	//Добавление юзера в заданную комнату
	room.usersInRoom.push_back(&user);
}
