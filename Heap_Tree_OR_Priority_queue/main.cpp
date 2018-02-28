#include "Heap.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

int main()
{
	Heap<int> obj = { 0, 1, 5, 9, 7, 6, 35, 18, 30 };
	
	srand(time(NULL));

	for (int i = 0; i < 20; ++i)
	{
		int c = rand() % 150;
		obj.insert(c);
	}

	int max_size_heap = obj.size();

	for (int i = 0; i < max_size_heap; ++i)
	{
		std::cout << obj.Root() << " " ; 
	}
	std::cout << '\n';
	
	system("pause");
	return 0;
}