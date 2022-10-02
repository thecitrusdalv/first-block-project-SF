#include <iostream>

#include "server.h"
#include "entry.h"
#include "login.h"

int main ()
{
	Server server ("server");
	server.addUser("citrus","1234","cit");
	server.addUser("roma","1234","romych");
	entry(server);
	return 0;
}
