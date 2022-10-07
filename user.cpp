//user.cpp

#include "user.h"
#include "room.h"

//constr,destr
	User::User(const std::string& login, const std::string& pass, const std::string& name)
	: m_login(login), m_pass(pass), m_name(name) {}

	User::User(const User&) = default;

	User::~User() = default;
	
//operators
	void User::operator= (const User&) = delete;

//getters
	const std::string& User::getLogin() const
	{
		return m_login;
	}

	const std::string& User::getPass() const
	{
		return m_pass;
	}

	const std::string& User::getName() const
	{
		return m_name;
	}

//methods
	int User::addMsg(const Msg& msg)
	{
		msgVec.push_back(msg);
		return msgVec.size();
	}

	void User::showMsg()
	{
		std::cout << '\n';
		for (; readedCount < msgVec.size(); readedCount++) {
			std::cout << '\t' << msgVec[readedCount].name << ": " <<
				msgVec[readedCount].message << '\n';
		}
		std::cout << std::endl;

		readedCount = msgVec.size();
	}

//friends
	std::ostream& operator<< (std::ostream& out, const User& user)
{
	out << "Login: " << user.m_login << '\n';
	out << "Pass: " << user.m_pass << '\n';
	out << "Name: " << user.m_name << '\n';
	out << "In room: " << user.roomPtr->getName();

	return out;
}
