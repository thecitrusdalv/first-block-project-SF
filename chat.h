//chat.h
#pragma once

#include <vector>
#include <string>

#include "userMsg.h"

using std::string;

class Chat
{
	string m_name;
	std::vector <UserMsg> MsgVec;
public:
	Chat (const string&);
	virtual ~Chat ();

	virtual void addMsg (const UserMsg&);
	virtual const string& getName() const;
};
