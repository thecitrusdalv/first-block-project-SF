//reg.cpp

#include "reg.h"

int reg(Server &server)
{
	std::string login, pass, name;

	for (;;) {
		std::cout << "Login: ";
		std::cin >> login; std::cin.ignore(1000, '\n');

		if(login.empty()) {
			std::cout << "\tCannot be empty" << std::endl;
			continue;
		}

		if (server.findLogin(login) != NOT_FOUND) {
			std::cout << "\tLogin unavailable" << std::endl;
			continue;
		}
		else
			break;
	}

	for (;;) {
		std::cout << "Password: ";
		std::cin >> pass; std::cin.ignore(1000, '\n');
		if (pass.empty()) {
			std::cout << "\tCannot be empty" << std::endl;
			continue;
		}
		else
			break;
	}

	for (;;) {
		std::cout << "Name: ";
		std::cin >> name; std::cin.ignore(1000, '\n');

		if (pass.empty()) {
			std::cout << "\tCannot be empty" << std::endl;
			continue;
		}

		if (server.findName(name) != NOT_FOUND) {
			std::cout << "\tName unavailable" << std::endl;
			continue;
		}
		else
			break;
	}

	return server.addUser(login, pass, name);
}

