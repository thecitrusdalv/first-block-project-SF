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
			std::cin >> login;

		if (login == "exit")
			break;
		
		if (login == ":exit")
			exit(0);

		int index;
		if ( (index = server.findLogin(login)) != NOT_FOUND) {
			std::cout << "Password: ";
				std::cin >> pass;

			if (users[index].getPass() == pass) {
				std::cout << "\tHello, " <<
					users[index].getName() << ".\n" << std::endl;

				userSpace(users[index], server);
			}
			else
				std::cout << "\tIncorrect password" << std::endl;
		}
		else
			std::cout << "\tLogin not found" << std::endl;
	}
}
