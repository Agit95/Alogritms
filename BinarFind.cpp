#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

template<typename T>
int BinarFind(std::vector<T> &vec, int size, T obj)
{
	int r = size - 1;
	int m;

	for (int l = 0; r < size, l <= r;)
	{
		m = (l + r) / 2;
		if (vec[m] == obj)
		{
			return l;
		}
		if (vec[m] < obj)
		{
			l = m + 1;
		}
		if (vec[m] > obj)
		{
			r = m - 1;
		}
	}
	return -1;
}

int main()
{
	std::vector<int> vec = { 5, 9, 10, 15, 18, 26, 50, 56, 75, 89 };
	srand(time(NULL));

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << BinarFind(vec, vec.size(), 50) << std::endl;

}