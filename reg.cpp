//reg.cpp

#include "reg.h"

int reg(Server &server)
{
	std::string login, pass, name;

	for (;;) {
		std::cout << "Login: ";
		std::cin >> login;

		if(login.empty()) {
			std::cout << "Cannot be empty" << std::endl;
			continue;
		}

		if (server.findLogin(login) != NOT_FOUND) {
			std::cout << "Login unavailable" << std::endl;
			continue;
		}
		else
			break;
	}

	for (;;) {
		std::cout << "Password: ";
		std::cin >> pass;
		if (pass.empty()) {
			std::cout << "Cannot be empty" << std::endl;
			continue;
		}
		else
			break;
	}

	for (;;) {
		std::cout << "Name: ";
		std::cin >> name;

		if (pass.empty()) {
			std::cout << "Cannot be empty" << std::endl;
			continue;
		}

		if (server.findName(name) != NOT_FOUND) {
			std::cout << "Name unavailable" << std::endl;
			continue;
		}
		else
			break;
	}

	return server.addUser(login, pass, name);
}

