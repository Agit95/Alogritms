#include "Polinom.h"

int main()
{
	Polynom temp_obj , tempobj;

	Node node_obj , *node;
	node = &node_obj;

	for (int i = 0; i < 5; ++i)
	{
		node->m_oCoefficient = i + 10;
		node->m_oExponent = i + 1;
		temp_obj.add_term(node);
	}

	for (int i = 5; i < 10; ++i)
	{
		node->m_oCoefficient = i + 10;
		node->m_oExponent = i + 1;
		tempobj.add_term(node);
	}
	node->m_oCoefficient = 17;
	node->m_oExponent = 7;
	temp_obj.add_term(node);

	node->m_oCoefficient = 16;
	node->m_oExponent = 6;
	temp_obj.add_term(node);

	Polynom temp = tempobj - temp_obj;
	
	Polynom temp_1 = tempobj + temp_obj;

	std::cout << temp_1 << std::endl;
	std::cout << '\n';
	std::cout << temp << std::endl;
	std::cout << '\n';
	std::cout << temp_obj << std::endl;
	std::cout << '\n';
	std::cout << tempobj << std::endl;

	system("pause");
	return 0;
}