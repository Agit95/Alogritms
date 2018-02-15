#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stack>


int main()
{	
	std::stack<char *>  stek;
	char ch[] = "asdas dasfsd fsdfs fergwr fwefw fwfwg4 56fef";
	int i = strlen(ch);
	char * point = strtok(ch ," ");
	while (point != NULL)
	{
		stek.push(point);
		point = strtok(NULL, " ");
	}

	std::string s;

	while (!stek.empty())
	{
		s+=stek.top();
		stek.pop();
		if (!stek.empty())
			s += ' ';
	}

	std::cout << s.c_str() << std::endl;
	return 0;

}