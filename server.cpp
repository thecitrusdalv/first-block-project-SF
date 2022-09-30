//server.cpp

#include "server.h"

//constr, destr
	Server::Server(const std::string& name) : m_name(name) {}

	Server::Server(const Server&) = delete;

	Server::~Server() = default;

//operators
	void Server::operator= (const Server&) = delete;
	
//methods
	int Server::findName(const std::string& name)
	{
		for (size_t i = 0; i < usersVec.size(); i++) {
			if (usersVec[i].getName() == name)
				return i;
		}

		return NOT_FOUND;
	}

	int Server::findLogin(const std::string& login)
	{
		for (size_t i = 0; i < usersVec.size(); i++) {
			if (usersVec[i].getLogin() == login)
				return i;
		}

		return NOT_FOUND;
	}

	int Server::findUser(const std::string& login,
			const std::string& name)
	{
		for (size_t i = 0; i < usersVec.size(); i++) {
			if (usersVec[i].getLogin() == login ||
					usersVec[i].getName() == name) {
				return i;
			}
		}

		return NOT_FOUND;
	}

	int Server::findRoom(const std::string& name)
	{
		for (size_t i = 0; i < roomsVec.size(); i++) {
			if (roomsVec[i].getName() == name)
				return i;
		}

		return NOT_FOUND;
	}

	int Server::addUser(const std::string& login,
				const std::string& pass,
					const std::string& name)
	{
		if ( findUser(login, name) == NOT_FOUND ) {
			usersVec.emplace_back( User(login, pass, name) );
			return usersVec.size()-1;
		}
		else
			return FAILED;
	}

	int Server::addRoom(const std::string& name)
	{
		if (findRoom(name) == NOT_FOUND) {
			roomsVec.emplace_back( Room(name) );
			return roomsVec.size()-1;
		}
		else
			return FAILED;
	}

//getters
	const std::vector<User>& Server::getUsersVec() const
	{
		return usersVec;
	}

	const std::vector<Room>& Server::getRoomsVec() const
	{
		return roomsVec;
	}

//friends
	std::ostream& operator<< (std::ostream& out, const Server& server)
	{
		out << "Server: " << server.m_name << '\n';
		out << "Rooms: ";
		for (size_t i = 0; i < server.roomsVec.size(); i++) {
			out << "\n\t" << server.roomsVec[i].getName();
		}
		return out;
	}
