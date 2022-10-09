//room.h
#pragma once

#include <iostream>
#include <vector>

#include "msg.h"

class User;

class Room
{
	const std::string m_name;	//Имя комнаты.
	std::vector<User*> usersInRoom;	//Вектор юзеров в комнате.
	std::vector<Msg> msgVec;	//Вектор сообщений комнаты.

public:
//constr, destr
	Room(const std::string&);

	Room(const Room&);

	~Room();

//operators
	void operator= (const Room&);
	
//getters
	const std::string& getName() const;
	
//methods
	int addMsg(const Msg&);	//Добавление сообщения в комнату.
	void showMsg() const;	//Вывод сообщений комнаты.
	void showUsers() const;	//Вывод юзеров в комнате

//friends
	friend void join(User&, Room&);
	friend std::ostream& operator<< (std::ostream&, const Room&);
};
