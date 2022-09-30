//server.h
#pragma once

#include <vector>
#include <iostream>

#include "user.h"
#include "room.h"

enum serverErrors {
	FAILED		= -1,
	NOT_FOUND	= -2
};

class Server
{
	const std::string m_name;
	std::vector<User> usersVec;
	std::vector<Room> roomsVec;
public:
//constr, destr
	Server(const std::string&);

	Server(const Server&);

	~Server();
	
//operators
	void operator= (const Server&);

//methods
	int addUser(const std::string&,
			const std::string&,
			const std::string&);

	int addRoom(const std::string&);

	int findName(const std::string&);

	int findLogin(const std::string&);

	int findUser(const std::string&, const std::string&);

	int findRoom(const std::string&);

//getters
	const std::vector<User>& getUsersVec() const;
	const std::vector<Room>& getRoomsVec() const;
	
//friends
	friend std::ostream& operator<< (std::ostream&, const Server&);
	friend void join (User&, Room&);
};
