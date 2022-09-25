//findChat.h
#pragma once

#include <string>
#include <vector>

#include "chat.h"

enum errors {
	CHAT_NOT_FOUND = -1
};

int findChat (const std::vector<Chat>&, const std::string&);
