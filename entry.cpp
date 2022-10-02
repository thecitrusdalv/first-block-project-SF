//entry.cpp

#include "entry.h"

void entry(Server& server)
{
	std::string choise;

	for (;;) {
		std::cout << "login/register?: ";
		std::cin >> choise;

		if (choise == "login") {
			login(server);
		}

		if (choise == "register") {
			reg(server);
		//	join(server.usersVec.back(), server.roomsVec[0]);
		}

		if (choise == ":exit") {
			exit(0);
		}
	}
}
