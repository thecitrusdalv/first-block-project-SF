//loginReq.cpp

#include <iostream>
#include <vector>

#include "loginReq.h"
#include "chat.h"
#include "logUser.h"
#include "regUser.h"

void loginReq(std::vector<Chat> &chatList)
{
	std::string choise;

	for (;;) {
		std::cout << "login/register?" << std::endl;
		std::cin >> choise;

		if (choise == "exit")
			exit(0);

		if (choise == "login") {
			logUser();
		}
		else if (choise == "register") {
			regUser();
		}
		else {}
	}
}
