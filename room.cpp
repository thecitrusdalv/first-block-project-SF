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

//methods
	int Room::addMsg(const Msg& msg)
	{
		msgVec.push_back(msg);
		return msgVec.size();
	}

	void Room::showMsg() const
	{
		for (size_t i = 0; i < msgVec.size(); i++) {
			std::cout << "\t-> " << msgVec[i].name << ": " <<
				msgVec[i].message << std::endl;
		}
	}

	void Room::showUsers() const
	{
		std::cout << '\n';
		for (size_t i = 0; i < usersInRoom.size(); i++) {
			std::cout << '\t' << usersInRoom[i]->getName() << '\n';
		}
		std::cout << std::endl;
	}

//friends
	std::ostream& operator<< (std::ostream& out, const Room& room)
	{
		out << "Room: " << room.m_name << '\n';

		out << "Users:" << '\n';
		for (size_t i = 0; i < room.usersInRoom.size(); i++) {
			out << '\t' << room.usersInRoom[i]->getName() << '\n';

			//if (i != room.usersInRoom.size()-1)
				//out << '\n';
		}

		out << "Messages:" << '\n';
		for (size_t i = 0; i < room.msgVec.size(); i++) {
			out << '\t' << room.msgVec[i].name << ": " <<
				room.msgVec[i].message << '\n';
		}

		return out;
	}
