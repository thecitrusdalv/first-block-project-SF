//room.cpp

#include "room.h"
#include "user.h"

//constr, destr
	Room::Room(const std::string& name) : m_name(name) {}

	Room::Room(const Room&) = default;

	Room::~Room() = default;

//operators
	void Room::operator= (const Room&) = delete;
	
//getters
	const std::string& Room::getName() const
	{
		return m_name;
	}

//friends
	std::ostream& operator<< (std::ostream& out, const Room& room)
	{
		out << "Room: " << room.m_name << '\n';
		out << "Users:" << '\n';
		for (size_t i = 0; i < room.usersInRoom.size(); i++) {
			out << '\t' << room.usersInRoom[i]->getName();

			if (i != room.usersInRoom.size()-1)
				out << '\n';
		}

		return out;
	}
