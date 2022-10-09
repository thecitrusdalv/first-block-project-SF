//login.cpp

#include "login.h"

#define users server.usersVec

void login(Server& server)
{
	std::string input; //Строка для ввода

	std::cout << "\tType \"back\" to cancel" << std::endl;

	for (;;) {
		std::cout << "Login: ";
		std::cin >> input; std::cin.ignore(1000, '\n');

		//Генерирование исключения если что то с потоком ввода
		if (std::cin.fail())
			throw ("cin fail. login.cpp");

		//Возврат в прошлое меню
		if (input == "back")
			return;
		
		//Завершение
		if (input == "exit")
			exit(0);

		//Индекс найденного юзера
		int index;

		//Если логин на сервере найден, запрос пароля
		if ( (index = server.findLogin(input)) != NOT_FOUND) {
			std::cout << "Password: ";
			std::cin >> input; std::cin.ignore(1000, '\n');

			if (std::cin.fail())
				throw ("cin fail. login.cpp");

			//Если пароль верен, вызов следующей функции
			if (users[index].getPass() == input) 
				userSpace(users[index], server);
			else
				std::cout << "\tIncorrect password" << std::endl;
		}
		else
			std::cout << "\tLogin not found" << std::endl;
	}
}
