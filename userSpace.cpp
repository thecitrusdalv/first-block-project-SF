//userSpace.cpp

#include <cstdlib>

#include "server.h"

void userSpace(User& user, Server& server) {

	join(user, user.roomPtr ? *(user.roomPtr) : server.roomsVec[0]);

	std::string input;
	std::cin.ignore();
	std::system("clear");
	(user.roomPtr)->showMsg();

	for (;;) {
		std::cout << user.getName() << ": ";
		std::getline(std::cin, input);

		if (input == ":out")
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

		if (input == ":join") {
			std::string room;
			std::cout << "Room: ";
				std::cin >> room;

			int foundRoom;
			if ( (foundRoom = server.findRoom(room)) != NOT_FOUND) {
				join (user, server.roomsVec[foundRoom]);
				std::system("clear");
				(user.roomPtr)->showMsg();

				std::cin.ignore();
				continue;
			}
			else
				std::cout << "Room not found" << std::endl;


			continue;
		}

		if (input == ":list") {
			user.roomPtr->showUsers();
			continue;
		}

		user.roomPtr->addMsg({user.getName(), input});
		std::system("clear");
		(user.roomPtr)->showMsg();
	}
}
