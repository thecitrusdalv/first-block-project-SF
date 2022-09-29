//server.cpp

#include <vector>

#include "server.h"
#include "find.h"

//constr, destr
	Server::Server(const std::string& name) : m_name(name) {}

	Server::Server(const Server&) = delete;

	Server::~Server() = default;

//operators
	void Server::operator= (const Server&) = delete;
	
//methods
	int Server::addUser(const std::string& login, const std::string& pass, const std::string& name)
	{
		if ( findUser(*this, login, name) == NOT_FOUND ) {
			usersVec.emplace_back( User(login, pass, name) );
			return usersVec.size()-1;
		}
		else
			return FAILED;
	}

	int Server::addRoom(const std::string& name)
	{
		if (findRoom(*this, name) == NOT_FOUND) {
			roomsVec.emplace_back( (Room(name)) );
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
