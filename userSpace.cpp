//userSpace.cpp

#include <cstdlib>

#include "server.h"
#include "find.h"


void userSpace(User& user, Server& server) {

	//Если пользователь логинится в первый раз, его закидывает в комнату "general"
	//Если пользователь был в какой либо комнате, он возвращается к ней.
	join(user, user.roomPtr ? *(user.roomPtr) : server.roomsVec[0]);

	//Строка для ввода сообщения или команды.
	std::string input;

	//При добавлении ключей LINUX или WIN при компиляции,
	//включается очищение экрана.
	#ifdef LINUX
	std::system("clear");
	#endif

	#ifdef WIN
	std::system("cls");
	#endif

	//Вывод всех сообщений комнаты.
	user.roomPtr->showMsg();

	//Определение количества приватных сообщений.
	std::cout << "You have " << user.msgVec.size()-user.readedCount << " private message(s)\n";

	//Вектор возможных команд
	std::vector<std::string> commands = {
		"list", "join", "room", "user", "priv", "help"
	};

	//Перечисление команд для избавления в дальнейшем от магических чисел
	//в операторе выбора switch()
	enum enumCommands {
		LIST, JOIN, ROOM, USER, PRIV, HELP
	};

	//Главный цикл пространства пользователя.
	for (;;) {
		//Приглашение к вводу
		std::cout << "-> " << user.m_name << ": ";

		//Ввод
		std::getline(std::cin, input);
		if (std::cin.fail())
			throw ("cin fail. userSpace.cpp");


		//Если первый символ в строке ввода ':',
		//сообщение определяется как команда.
		if (input[0] == ':') {

			std::string temp; //Заводится временная строка.
			std::vector<std::string> CommandArgsVec; //Заводится вектор с командой и ее аргументами.

			//Данный цикл разделяет ввод на отдельные слова, добавляя их в вектор
			//CommandArgsVec
			for (size_t i = 1; i < input.size(); i++) {
				if (input[i] == ' ') {
					if (!temp.empty()) {
						CommandArgsVec.push_back(temp);
						temp.clear();
					}
				} else {
					temp += input[i];
				}
			}
			if (!temp.empty()) {
				CommandArgsVec.push_back(temp);
				temp.clear();
			}

			//Команда :out или :q осуществляет выход из учетной записи, путем прерывания главного цикла
			//пространства пользователя
			if ((CommandArgsVec[0] == "out") || (CommandArgsVec[0] == "q")) {

				#ifdef LINUX
				std::system("clear");
				#endif

				#ifdef WIN
				std::system("cls");
				#endif

				break;
			}

			if (CommandArgsVec[0] == "exit")
				exit(0);

			//Определение команды
			switch (findInVec<std::string> (commands, CommandArgsVec[0])) {
				case LIST: //Вывод пользователей в текущей комнате
					user.roomPtr->showUsers();
					break;

				case JOIN: //Подключение к другой комнате
					if (CommandArgsVec.size() != 2) {
						std::cout << "\tCommand <join> must have one argument" << std::endl;
						break;
					} else {
						int found;
						if ((found = server.findRoom(CommandArgsVec[1])) != NOT_FOUND) {
							join (user, server.roomsVec[found]);

							#ifdef LINUX
							std::system("clear");
							#endif

							#ifdef WIN
							std::system("cls");
							#endif

							user.roomPtr->showMsg();
						} else
							std::cout << "\tRoom not found" << std::endl;
					}
					break;

				case ROOM: //Выводит имя текущей комнаты
					std::cout << "\tRoom: " << user.roomPtr->getName() << std::endl;
					break;

				case USER: //Определяет дальнешие действия с определенным юзером на сервере
					if (CommandArgsVec.size() < 2) {
						std::cout << "\tCommand <user> must have at least one argument" << std::endl;
						break;
					}

					if (CommandArgsVec.size() == 2) {
						int found;
						if ( (found = server.findName(CommandArgsVec[1])) != NOT_FOUND ) {
							std::string message;
							std::cout << "\tMessage to " << server.usersVec[found].getName() << ": ";
							std::getline(std::cin, message);
							server.usersVec[found].addMsg({user.m_name, message});
						} else {
							std::cout << "\tUser <" << CommandArgsVec[1] <<
								"> not found" << std::endl;
						}
					}

					if (CommandArgsVec.size() > 2) {
						int found;
						if ( (found = server.findName(CommandArgsVec[1])) != NOT_FOUND ) {
							std::string message;
							for (size_t i = 2; i < CommandArgsVec.size(); i++) {
								message += CommandArgsVec[i];
								if (i != CommandArgsVec.size()-1)
									message += ' ';
							}
							server.usersVec[found].addMsg({user.m_name, message});
						} else {
							std::cout << "\tUser <" << CommandArgsVec[1] <<
								"> not found" << std::endl;
						}
					}

					break;

				case PRIV: //Показ приватных сообщений
					user.showMsg();
					break;

				case HELP: //Вывод справки
					std::cout << "\tPossible commands:\n" <<
					"\t:list\t - listing of all users in current room;\n" <<
					"\t:join\t - join to another room (:join <room>)\n" <<
					"\t:room\t - show name of current room\n" <<
					"\t:user\t - send private message to other users " <<
						"(:user <name> or :user <name> <message>)\n" <<
					"\t:priv\t - show private messages from other users\n\n" <<
					"\t:out/q\t - logout from current user\n" <<
					"\t:exit\t - exit from program" << std::endl;
					break;

				default:
					std::cout << "\tCommand not found" << std::endl;
					break;
			}

		} else {

			//Если небыло команд, добавление сообщения в текущую комнату
			user.roomPtr->addMsg({user.m_name, input});

			#ifdef LINUX
			std::system("clear");
			#endif

			#ifdef WIN
			std::system("cls");
			#endif

			user.roomPtr->showMsg();
		}
	}
}
