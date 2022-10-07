//login.cpp

#include "login.h"
#include "userSpace.h"

#define users server.usersVec

void login(Server& server)
{
	std::string login;
	std::string pass;

	for (;;) {
		std::cout << "Login: ";
		std::cin >> login; std::cin.ignore(1000, '\n');

		if (login == "back")
			break;
		
		if (login == "exit")
			exit(0);

		int index;
		if ( (index = server.findLogin(login)) != NOT_FOUND) {
			std::cout << "Password: ";
			std::cin >> pass; std::cin.ignore(1000, '\n');

			if (users[index].getPass() == pass) 
				userSpace(users[index], server);
			else
				std::cout << "\tIncorrect password" << std::endl;
		}
		else
			std::cout << "\tLogin not found" << std::endl;
	}
}
