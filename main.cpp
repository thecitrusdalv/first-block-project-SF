#include <iostream>
#include <exception>

#include "server.h"
#include "entry.h"

int main ()
{
	try {
		Server server ("server");	//Создание сервера.
									//Присваивание имени через конструктор

		server.addRoom("second");	//Добавление дополнительной команты в сервер. (По
									//умолчанию сервер имеет комнату "general").

		entry(server); //Вход в созданный сервер.
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (const char* message)
	{
		std::cerr << "\nError: " << message << std::endl;
	}
	catch (...)
	{
		std::cerr << "\nUndefined error" << std::endl;
	}

	return 0;
}
