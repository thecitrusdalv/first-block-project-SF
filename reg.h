//reg.h
#pragma once

#include <iostream>

#include "server.h"

//Регистрация нового юзера. Возвращает индекс юзера в векторе на сервере.
//Возврат -1 (FAILED) если не удалось.
int reg(Server&);

