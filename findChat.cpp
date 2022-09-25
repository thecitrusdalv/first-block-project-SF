//findChat.cpp

#include "findChat.h"
#include "chat.h"
#include <vector>
#include <string>

int findChat(const std::vector<Chat> &vec, const std::string &name)
{
	for (size_t i = 0; i < vec.size(); i++) {
		if (vec[i].getName() == name)
			return i;
	}

	return CHAT_NOT_FOUND;
}



