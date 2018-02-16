#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector> 
#include <stdlib.h>
#include <ctime>

template<typename T>
void Quick_Sort(std::vector<T> &a, int first, int last)
{
	int i = first, j = last;
	T x = a[(first + last) / 2];
	do {
		while (a[i] < x)
		{
			i++;
		}
		while (a[j] > x)
		{
			j--;
		}
		if (i <= j)
		{
			std::swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last)
	{
		Quick_Sort(a, i, last);
	}
	if (first < j)
	{
		Quick_Sort(a, first, j);
	}
}


int main()
{
	std::vector<int> vec;
	srand(time(NULL));
	for (int i = 0; i < 20;++i)
	{
		vec.push_back(rand() % 100);
	}
	
	for (int i = 0; i < 20; ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	Quick_Sort(vec, 0, vec.size() - 1);

	for (int i = 0; i < 20; ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

}