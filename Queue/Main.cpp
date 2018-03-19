#include <iostream>
#include "My_Queue.h"


int main()
{
	My_Queue<int> obj;

	for (int i = 0; i < 20; ++i)
	{
		obj.enqueue(i);
	}

	for (int i = 0; i < 20; ++i)
	{
		std::cout << obj.dequeuee() << std::endl;
	}

	system("pause");
	return 0;
}