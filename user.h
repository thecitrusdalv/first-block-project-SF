//user.h
#pragma once

#include <iostream>
#include <vector>

#include "msg.h"

class Room;

class User
{
	const std::string m_login, m_pass, m_name;
	Room *roomPtr = nullptr;
	std::vector<Msg> msgVec;

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
	void showMsg() const;

//friends
	friend void join(User&, Room&);
	friend std::ostream& operator<< (std::ostream&, const User&);
};
