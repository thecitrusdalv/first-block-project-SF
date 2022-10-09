//reg.cpp

#include "reg.h"

int reg(Server &server)
{
	std::cout << "\tType \"back\" to cancel" << std::endl;

	std::string login, pass, name;

	//Ввод логина
	for (;;) {
		std::cout << "Login: ";
		std::cin >> login; std::cin.ignore(1000, '\n');

		if(login == "back")
			return FAILED;

		if(std::cin.fail()) {
			throw ("cin fail. reg.cpp");
		}

		if (server.findLogin(login) != NOT_FOUND) {
			std::cout << "\tLogin unavailable" << std::endl;
			continue;
		}
		else
			break;
	}

	//Ввод пароля
	for (;;) {
		std::cout << "Password: ";
		std::cin >> pass; std::cin.ignore(1000, '\n');

		if(pass == "back")
			return FAILED;

		if(std::cin.fail()) {
			throw ("cin fail. reg.cpp");
		}
		else
			break;
	}

	//Ввод имени
	for (;;) {
		std::cout << "Name: ";
		std::cin >> name; std::cin.ignore(1000, '\n');

		if(name == "back")
			return FAILED;

		if(std::cin.fail()) {
			throw ("cin fail. reg.cpp");
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
