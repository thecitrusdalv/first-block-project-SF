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
	Room *roomPtr = nullptr;
	std::vector<Msg> msgVec;
	size_t readedCount = 0;

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
	int addMsg(const Msg&);
	void showMsg();

//friends
	friend void join(User&, Room&);
	friend void userSpace(User&, Server&);
	friend void list(User&, Server&, const std::vector<std::string>&);
	friend std::ostream& operator<< (std::ostream&, const User&);
};
