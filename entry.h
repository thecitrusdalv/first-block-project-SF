//entry.h
#pragma once

#include <iostream>
#include <vector>

#include "server.h"

template <typename TYPE>
int findInVec(const std::vector<TYPE> &vec, const TYPE& obj)
{
	for (size_t i = 0; i < vec.size(); i++) {
		if (vec[i] == obj)
			return i;
	}

	return -1;
}

void entry(Server&);

