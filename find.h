//find.h
#pragma once

#include <string>

#include "server.h"

enum findErrors {
	NOT_FOUND = -1,
};


int findLogin(const Server&, const std::string&);
int findName(const Server&, const std::string&);
int findUser(const Server&, const std::string&,
		const std::string&);
int findRoom(const Server&, const std::string&);
