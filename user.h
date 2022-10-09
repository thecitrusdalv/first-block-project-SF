//user.h
#pragma once

#include <iostream>
#include <vector>

#include "msg.h"

class Server;
class Room;

class User
{
	const std::string m_login, m_pass;
	std::string m_name;
	Room *roomPtr = nullptr;	//Указатель на текущую комнату, по умолчанию нет.
	std::vector<Msg> msgVec;	//Вектор приватных сообщений.
	size_t readedCount = 0;		//Переменная для учета прочтенных приватных сообщений.

public:
	User(const std::string&, const std::string&, const std::string&);

	User(const User&);

	~User();

	void operator= (const User&);

//getters
	const std::string& getLogin() const;
	const std::string& getPass() const;
	const std::string& getName() const;

//methods
	int addMsg(const Msg&); //Добавление приватного сообщения
	void showMsg(); //Вывод приватных сообщений

//friends
	friend void join(User&, Room&);
	friend void userSpace(User&, Server&);
	friend void list(User&, Server&, const std::vector<std::string>&);
	friend std::ostream& operator<< (std::ostream&, const User&);
};
