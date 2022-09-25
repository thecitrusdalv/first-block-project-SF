//main.cpp
#include <iostream>
#include <vector>

#include "chat.h"
#include "user.h"
#include "userMsg.h"
#include "findChat.h"
#include "loginReq.h"

using std::cout;
using std::cin;
using std::string;

int main ()
{
	std::vector<Chat> chatList = {
		User("citrus","citrus","1234"),
		Chat("general"),
		Chat("second")
	};

	loginReq(chatList);

	return 0;
}
