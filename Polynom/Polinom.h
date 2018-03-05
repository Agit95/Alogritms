#ifndef POLYNOM_H
#define POLYNOM_H

#include <iostream>

//node of polinome
struct Node
{
	int    m_oCoefficient;
	int    m_oExponent;
	Node*  m_pNext;

	Node():m_oCoefficient(0),m_oExponent(0)
	{
		m_pNext = nullptr;
	}
};

//polynom  class  declaration
class Polynom
{
private:
	Node* m_pRoot;
	int   m_oSize;

public:				 
	Polynom();
	~Polynom();
	void add_term(Node*);
	friend const Polynom& operator -(const Polynom&,const Polynom&);
	friend const Polynom& operator +(const Polynom&,const Polynom&);
	friend std::ostream& operator <<(std::ostream&, const Polynom&);
		

	const Polynom& operator =(const Polynom& obj1)
	{
		Node* obj = obj1.m_pRoot;
		Node* temp_this_root = this->m_pRoot;
		Node* temp_ptr = obj;
		while (obj != nullptr)
		{
			this->m_pRoot->m_oCoefficient = obj->m_oCoefficient;
			this->m_pRoot->m_oExponent = obj->m_oExponent;
			this->m_pRoot->m_pNext = obj->m_pNext;
			this->m_pRoot = this->m_pRoot->m_pNext;
			obj = obj->m_pNext;
		}
		this->m_pRoot = temp_this_root;
		obj = temp_ptr;

		return *this;
	}


};
#endif // POLYNOM_H	  