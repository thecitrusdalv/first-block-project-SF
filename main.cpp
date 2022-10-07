#include <iostream>
#include <exception>

#include "server.h"
#include "entry.h"
#include "login.h"

int main ()
{
	try {
		Server server ("server");
		server.addRoom("second");

		server.addUser("citrus","1234","citrus");
		server.addUser("roma","1234","roma");

		entry(server);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
