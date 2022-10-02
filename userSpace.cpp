//userSpace.cpp

#include "server.h"

void userSpace(User& user, Server& server) {

	join(user, server.roomsVec[0]);

	(user.roomPtr)->showMsg();

	std::string input;
	std::cin.ignore();
	for (;;) {
		std::cout << user.getName() << ": ";
		std::getline(std::cin, input);

		if (input == ":logout")
			break;

		if (input == ":exit")
			exit(0);

		if (input == ":change name") {
			std::string name;
			std::cout << "New name: ";
				std::cin >> name;
			user.m_name = name; 
			std::cin.ignore();

			continue;
		}

		else
			user.roomPtr->addMsg({user.getName(), input});
	}
}
