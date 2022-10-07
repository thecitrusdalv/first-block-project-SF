//userSpace.cpp

#include <cstdlib>

#include "server.h"
#include "find.h"

#ifdef LINUX
	#define CLEAN std::system("clear")
#endif

#ifdef WIN
	#define CLEAN std::system("cls")
#endif

void userSpace(User& user, Server& server) {

	join(user, user.roomPtr ? *(user.roomPtr) : server.roomsVec[0]);

	std::string input;

	CLEAN;

	user.roomPtr->showMsg();
	std::cout << "You have " << user.msgVec.size()-user.readedCount << " private message(s)\n";

	std::vector<std::string> commands = {
		"list", "join", "room", "user", "priv", "help"
	};

	enum enumCommands {
		LIST, JOIN, ROOM, USER, PRIV, HELP
	};

	for (;;) {
		std::cout << "-> " << user.m_name << ": ";
		std::getline(std::cin, input);

		std::string temp;
		std::vector<std::string> CommandArgsVec;

		if (input[0] == ':') {

			for (size_t i = 1; i < input.size(); i++) {
				if (input[i] == ' ') {
					if (!temp.empty()) {
						CommandArgsVec.push_back(temp);
						temp.clear();
					}
				} else {
					temp += input[i];
				}
			}
			if (!temp.empty()) {
				CommandArgsVec.push_back(temp);
				temp.clear();
			}

			if ((CommandArgsVec[0] == "out") || (CommandArgsVec[0] == "q")) {
				CLEAN;
				break;
			}

			if (CommandArgsVec[0] == "exit")
				exit(0);

			switch (findInVec<std::string> (commands, CommandArgsVec[0])) {
				case LIST:
					user.roomPtr->showUsers();
					break;

				case JOIN:
					if (CommandArgsVec.size() != 2) {
						std::cout << "\tCommand <join> must have one argument" << std::endl;
						break;
					} else {
						int found;
						if ((found = server.findRoom(CommandArgsVec[1])) != NOT_FOUND) {
							join (user, server.roomsVec[found]);
							CLEAN;
							user.roomPtr->showMsg();
						} else
							std::cout << "\tRoom not found" << std::endl;
					}
					break;

				case ROOM:
					std::cout << "\tRoom: " << user.roomPtr->getName() << std::endl;
					break;

				case USER:
					if (CommandArgsVec.size() < 2) {
						std::cout << "\tCommand <user> must have at least one argument" << std::endl;
						break;
					}

					if (CommandArgsVec.size() == 2) {
						int found;
						if ( (found = server.findName(CommandArgsVec[1])) != NOT_FOUND ) {
							std::string message;
							std::cout << "\tMessage to " << server.usersVec[found].getName() << ": ";
							std::getline(std::cin, message);
							server.usersVec[found].addMsg({user.m_name, message});
						} else {
							std::cout << "\tUser <" << CommandArgsVec[1] <<
								"> not found" << std::endl;
						}
					}

					if (CommandArgsVec.size() > 2) {
						int found;
						if ( (found = server.findName(CommandArgsVec[1])) != NOT_FOUND ) {
							std::string message;
							for (size_t i = 2; i < CommandArgsVec.size(); i++) {
								message += CommandArgsVec[i];
								if (i != CommandArgsVec.size()-1)
									message += ' ';
							}
							server.usersVec[found].addMsg({user.m_name, message});
						} else {
							std::cout << "\tUser <" << CommandArgsVec[1] <<
								"> not found" << std::endl;
						}
					}

					break;

				case PRIV:
					user.showMsg();
					break;

				case HELP:
					std::cout << "Possible commands:\n" <<
					"\t:list\t - listing of all users in current room;\n" <<
					"\t:join\t - join to another room (:join <room>)\n" <<
					"\t:room\t - show name of current room\n" <<
					"\t:user\t - send private message to other users " <<
						"(:user <name> or :user <name> <message>)\n" <<
					"\t:priv\t - show private messages from other users\n\n" <<
					"\t:out|:q\t - logout from current user\n" <<
					"\t:exit\t - exit from program" << std::endl;
					break;

				default:
					std::cout << "\tCommand not found" << std::endl;
					break;
			}

		} else {
			user.roomPtr->addMsg({user.m_name, input});
			CLEAN;
			user.roomPtr->showMsg();
		}
	}
}
