//room.h
#pragma once

#include <iostream>
#include <vector>

#include "msg.h"

class User;

class Room
{
	const std::string m_name;
	std::vector<User*> usersInRoom;
	std::vector<Msg> msgVec;

public:
//constr, destr
	Room(const std::string&);

	Room(const Room&);

	~Room();

//operators
	void operator= (const Room&);
	
//getters
	const std::string& getName() const;

//friends
	friend void join(User&, Room&);
	friend std::ostream& operator<< (std::ostream&, const Room&);
};
