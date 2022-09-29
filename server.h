//server.h
#pragma once

#include <vector>

#include "user.h"
#include "room.h"

enum serverErrors {
	FAILED = -1
};

class Server
{
	const std::string m_name;
	std::vector<User> usersVec;
	std::vector<Room> roomsVec;
public:
//constr
	Server(const std::string&);

	Server(const Server&);
	
//destr
	~Server();
	
//operators
	void operator= (const Server&);

//methods
	int addUser(const std::string&,
			const std::string&,
			const std::string&);

	int addRoom(const std::string&);

//getters
	const std::vector<User>& getUsersVec() const;
	const std::vector<Room>& getRoomsVec() const;
	
};
