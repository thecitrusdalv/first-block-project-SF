//user.h
#pragma once

#include <string>
#include <vector>

#include "userMsg.h"
#include "chat.h"

using std::string;

class User final: public Chat 
{
	const string m_login;
	const string m_pass;
	uint16_t last_msg_id = 0;
public:

//constructor(s)
	User(
		const string&,
		const string&,
		const string&
	);

//destructor(s)
	~User();

//method(s)
	void sendMsg(const string&, const string&);
};
