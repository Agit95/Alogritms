#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

template<typename T>
void merge(std::vector<T> &vec, int l, int m, int r)
{
	int i = l;
	int j = m + 1;
	int k = 0;
	std::vector<T> temp(r - l + 1);
	while (i <= m && j <= r)
	{
		if (vec[i] < vec[j])
		{
			temp[k] = vec[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = vec[j];
			k++;
			j++;
		}
	}
	while (i <= m)
	{
		temp[k] = vec[i];
		k++;
		i++;
	}
	while (j <= r)
	{
		temp[k] = vec[j];
		k++;
		j++;
	}
	for (i = l; i <= r; i++)
	{
		vec[i] = temp[i - l];
	}
}

template<typename T>
void mergesort(std::vector<T> &vec, int l, int r)
{
	int m;
	if (l < r)
	{
		m = (l + r) / 2;
		mergesort(vec, l, m);
		mergesort(vec, m + 1, r);

		merge(vec, l, m, r);
	}
}

int main()
{
	srand(time(NULL));
	std::vector<int> vec;
	for (int i = 0; i < 20; i++)
	{
		vec.push_back(rand() % 100);
	}
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	mergesort(vec, 0, vec.size() - 1);
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	return 0;

}