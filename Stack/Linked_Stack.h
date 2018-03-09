#ifndef LINKED_STACK_H
#define	LINKED_STACK_H
#include <iostream>
#include "Stack_interface.h"

template <typename T>
struct Node
{
public:
	Node*  next;
	T      value;

	//constructor  by  defalut
	explicit Node() :value(0)	
	{
		next = nullptr;
	}
};

template<typename New_Type>
class Linked_Stack : public Stack_interface<New_Type>
{
private:
	Node<New_Type>* m_pRoot;
	int   m_oSize;

public:
	//default constructor
	explicit Linked_Stack() :m_oSize(0),Stack_interface<New_Type>()
	{
		try
		{
			m_pRoot = new Node<New_Type>();
		}
		catch (std::bad_alloc& b)
		{
			std::cout << b.what() << std::endl;
		}
	}

	//initalizer  value   of   the  Stack
	explicit Linked_Stack(std::initializer_list<New_Type> element):m_oSize(0),Stack_interface<New_Type>()
	{
		try
		{
			m_pRoot = new Node<New_Type>();
			for (auto e : element)
			{
				this->push(e);
			}
		}
		catch (std::bad_alloc& b)
		{
			std::cout << b.what() << std::endl;
		}
	}

	//Push  value  in  the  Stack
	virtual void push(const New_Type obj)
	{
		if (m_oSize == 0)	//push  first  element
		{
			m_pRoot->value = obj;
			++m_oSize;
		}
		else
		{
			try
			{
				Node<New_Type>* temp_node = new Node<New_Type>();
				temp_node->value = obj;
				temp_node->next = m_pRoot;
				m_pRoot = temp_node;
				++m_oSize;
			}
			catch (std::bad_alloc& b)
			{
				std::cout << b.what() << std::endl;
			}
		}
	}

	//pop object of  the  Stack
	virtual const New_Type pop()   _NOEXCEPT
	{
		if (isEmpty())
			return 0;

		Node<New_Type>* temp_node = m_pRoot;
		New_Type val = temp_node->value;
		m_pRoot = m_pRoot->next;
		delete temp_node;
		--m_oSize;
		return val;
	}

	//returned  count  of  elements  of  the  Stack
	virtual int length() _NOEXCEPT
	{
		return m_oSize;
	}

	//returned  top element  value  of  the  Stack
	virtual  const New_Type& topValue()	 _NOEXCEPT
	{
		if (isEmpty())
			return 0;
		return m_pRoot->value;
	}

	//returned  false  if  length==0 else true
	bool  isEmpty()	 _NOEXCEPT
	{
		return !length();
	}

	//clear  all objects  in  the  Stack
	void  clear()  _NOEXCEPT
	{
		if (isEmpty())
			return;

		while (m_pRoot->next != nullptr)
		{
			Node<New_Type>* temp = m_pRoot;
			m_pRoot = m_pRoot->next;
			delete temp;
		}
		m_oSize = 0;
	}

	virtual ~Linked_Stack()  _NOEXCEPT
	{
		if (isEmpty())
			return;

		while (m_pRoot->next!=nullptr)
		{
			Node<New_Type>* temp = m_pRoot;
			m_pRoot = m_pRoot->next;
			delete temp;
		}
		delete m_pRoot;
	}

	friend std::ostream& operator <<(std::ostream& output , const Linked_Stack& obj) 
	{
		Node<New_Type>* temp_ptr = obj.m_pRoot;
		while (temp_ptr->next != nullptr)
		{
			output << temp_ptr->value << " ";
			temp_ptr = temp_ptr->next;
		}
		output << temp_ptr->value;
		temp_ptr = obj.m_pRoot;
		return output;
	}
};

#endif // !LINKED_STACK_H

