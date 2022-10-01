//entry.cpp

#include "entry.h"


void entry(Server&)
{
	std::string choise;
	std::vector<std::string> commands = {
		"login",
		"register",
	};

	std::vector<std::string> exitCommands = {
		"exit", "quit", "q"
	};

	for (;;) {
		std::cout << "login/register?: ";
		std::cin >> choise;

		if (choise == "login") {
			//
		}

		if (choise == "register") {
			//
		}

		if (choise == "exit") {
			exit(0);
		}
	}
}
