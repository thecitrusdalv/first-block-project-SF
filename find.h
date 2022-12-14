//find.h
#include <vector>

//Поиск элемента в векторе и возврат его индекса, либо NOT_FOUND
template <typename TYPE>
int findInVec(const std::vector<TYPE> &vec, const TYPE& obj)
{
	for (size_t i = 0; i < vec.size(); i++) {
		if (vec[i] == obj)
			return i;
	}

	return NOT_FOUND;
}
