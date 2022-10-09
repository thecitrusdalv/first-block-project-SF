//entry.cpp

#include "entry.h"

void entry(Server& server)
{
	std::string choise; //Строка для ввода

	for (;;) {
		std::cout << "login/register/exit?: ";
		std::cin >> choise; std::cin.ignore(1000, '\n'); //Защита от многословного ввода

		if (choise == "login") {
			login(server);
		}

		if (choise == "register") {
			reg(server);
		}

		if (choise == "exit") {
			exit(0);
		}
	}
}
