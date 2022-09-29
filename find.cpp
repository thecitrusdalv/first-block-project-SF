//find.cpp

#include <string>

#include "find.h"
#include "server.h"

int findLogin(const Server& server, const std::string& login)
{
	const std::vector<User> &usersVec = server.getUsersVec();

	for (size_t i = 0; i < usersVec.size(); i++) {
		if (usersVec[i].getLogin() == login)
			return i;
	}

	return NOT_FOUND;
}

int findName(const Server& server, const std::string& name)
{
	const std::vector<User> &usersVec = server.getUsersVec();

	for (size_t i = 0; i < usersVec.size(); i++) {
		if (usersVec[i].getName() == name)
			return i;
	}

	return NOT_FOUND;
}

int findUser(const Server& server, const std::string& login,
		const std::string& name)
{
	const std::vector<User> &usersVec = server.getUsersVec();

	for (size_t i = 0; i < usersVec.size(); i++) {
		if ( usersVec[i].getLogin() == login || 
				usersVec[i].getName() == name ) {
			return i;
		}
	}
	return NOT_FOUND;
}

int findRoom(const Server& server, const std::string& name)
{
	const std::vector<Room> &roomsVec = server.getRoomsVec();

	for (size_t i = 0; i < roomsVec.size(); i++) {
		if (roomsVec[i].getName() == name)
			return i;
	}

	return NOT_FOUND;
}
