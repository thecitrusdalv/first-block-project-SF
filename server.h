//server.h
#pragma once

#include <vector>
#include <iostream>

#include "user.h"
#include "room.h"

//Глобальные константы с кодами ошибок
enum serverErrors {
	FAILED		= -1,
	NOT_FOUND	= -2
};

class Server
{
	const std::string m_name; //Имя сервера
	std::vector<User> usersVec; //Вектор юзеров, созданных на сервере.

	//Вектор комнат, созданных на сервере. По умолчанию есть комната "general".
	std::vector<Room> roomsVec = {{"general"}};
public:
//constr, destr
	Server(const std::string&);

	Server(const Server&);

	~Server();
	
//operators
	void operator= (const Server&);

//methods
	int addUser(const std::string&, //Добавление юзера на сервер
			const std::string&,
			const std::string&);

	int addRoom(const std::string&); //Добавление комнаты

	int findName(const std::string&); //Поиск по имени юзера

	int findLogin(const std::string&); //Поиск по логину

	int findUser(const std::string&, const std::string&); //Поиск юзера по имени или логину

	int findRoom(const std::string&); //Поиск комнаты по ее имени

//getters
	const std::vector<User>& getUsersVec() const;
	const std::vector<Room>& getRoomsVec() const;
	
//friends
	friend std::ostream& operator<< (std::ostream&, const Server&);
	friend void login(Server&);
	friend void join (User&, Room&);
	friend void entry (Server&);
	friend void userSpace(User&, Server&);
};
