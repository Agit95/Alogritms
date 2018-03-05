#include "Polinom.h"

Polynom::Polynom() :m_oSize(0)
{
	m_pRoot = new Node();
}

Polynom::~Polynom()
{
	while (m_pRoot->m_pNext != nullptr)
	{
		Node* temp = m_pRoot;
		m_pRoot = m_pRoot->m_pNext;
		delete temp;
	}
	delete m_pRoot;
}

void Polynom::add_term(Node* t_Node)
{
	if (t_Node->m_oCoefficient == 0)
		return;

	Node* temp_node = new Node();
	temp_node->m_oCoefficient = t_Node->m_oCoefficient;
	temp_node->m_oExponent = t_Node->m_oExponent;

	//avelacnum  enq  arajin element@
	if (m_oSize == 0)
	{
		m_pRoot = temp_node;
		++m_oSize;
		return;
	}

	//petqa  vor  root-@  het ga  skzbnakan vichakin
	Node* t_root_ptr = m_pRoot;
	//ogtagorcvelu  en shxrtayum  nor  noder  avelacnelu  hamar
	Node* temp_root_ptr = m_pRoot;
	Node* temp_root_next_ptr = m_pRoot->m_pNext;
	int j = 0;

	for (int i = 0; i < m_oSize; ++i)
	{
		if (m_pRoot->m_oExponent < temp_node->m_oExponent && i==0)
		{

			std::swap(m_pRoot->m_oCoefficient, temp_node->m_oCoefficient);
			std::swap(m_pRoot->m_oExponent, temp_node->m_oExponent);
			//tarr@  avelacnum  enq  listi  skzbum
			temp_node->m_pNext = temp_root_next_ptr;
			m_pRoot->m_pNext = temp_node;
			++m_oSize;
			break;
		}
		else if (m_pRoot->m_oExponent < temp_node->m_oExponent)
		{
			temp_root_ptr->m_pNext = temp_node;
			temp_node->m_pNext = m_pRoot;
			m_pRoot = t_root_ptr;
			++m_oSize;
			break;
		}
		else if (m_pRoot->m_oExponent == temp_node->m_oExponent)
		{
			m_pRoot->m_oCoefficient += temp_node->m_oCoefficient;
			m_pRoot = t_root_ptr;
			delete temp_node;
			break;
		}
		if (m_pRoot->m_pNext == nullptr)
		{
			m_pRoot->m_pNext = temp_node;
			m_pRoot = t_root_ptr;
			++m_oSize;
			break;
		}
		if (j != 0)
			temp_root_ptr = m_pRoot;
		m_pRoot = m_pRoot->m_pNext;
		++j;
	}
}

const Polynom& operator -(const Polynom& obj3,const Polynom& obj1)
{
	Node* obj2 = obj3.m_pRoot;
	Node* obj = obj1.m_pRoot;
	Node* temp_obj_root = obj;
	Node* temp_obj2_root = obj2;
	Polynom* newobj = new Polynom();
	while (obj2 != nullptr && obj != nullptr)
	{
		if (obj2->m_oExponent == obj->m_oExponent)
		{
			obj2->m_oCoefficient -= obj->m_oCoefficient;
			newobj->add_term(obj2);
			obj2 = obj2->m_pNext;
			obj = obj->m_pNext;
		}
		else if (obj2->m_oExponent > obj->m_oExponent)
		{
			//poxum enq  nshan@ vorovhetev   nshani popoxutyun  e  linelu
			obj->m_oCoefficient = -obj->m_oCoefficient;

			newobj->add_term(obj2);
			newobj->add_term(obj);
			//obyect@  berum enq  naxkin vichakin
			obj->m_oCoefficient = -obj->m_oCoefficient;
			obj2 = obj2->m_pNext;
			obj = obj->m_pNext;
		}
		else
		{
			//poxum enq  nshan@ vorovhetev   n\ani popoxutyun  e  linelu
			obj->m_oCoefficient = -obj->m_oCoefficient;

			newobj->add_term(obj2);
			newobj->add_term(obj);
			//obyect@  berum enq  naxkin vichakin
			obj->m_oCoefficient = -obj->m_oCoefficient;
			obj2 = obj2->m_pNext;
			obj = obj->m_pNext;
		}
	}
	//avelacnum  enq  mnacac  ktorner@
	if (obj2 != nullptr)
	{
		while (obj2 != nullptr)
		{
			newobj->add_term(obj2);
			obj2 = obj2->m_pNext;
		}
	}
	else if (obj != nullptr)
	{
		while (obj != nullptr)
		{
			obj->m_oCoefficient = -obj->m_oCoefficient; 
			newobj->add_term(obj);
			obj->m_oCoefficient = -obj->m_oCoefficient;
			obj = obj->m_pNext;
		}
	}

	obj2 = temp_obj2_root;
	obj = temp_obj_root;
	return  *newobj;
}

const Polynom& operator +(const Polynom& obj3,const Polynom& obj1)
{
	Node* obj2 = obj3.m_pRoot;
	Node* obj = obj1.m_pRoot;
	Node* temp_obj2_root = obj2;
	Node* temp_obj_root = obj;
	
	Polynom* newobj = new Polynom();
	while (obj2 != nullptr && obj != nullptr)
	{
		if (obj2->m_oExponent == obj->m_oExponent)
		{
			obj2->m_oCoefficient += obj->m_oCoefficient;
			newobj->add_term(obj2);
			obj2 = obj2->m_pNext;
			obj = obj->m_pNext;
		}
		else if (obj2->m_oExponent > obj->m_oExponent)
		{
			newobj->add_term(obj2);
			obj2 = obj2->m_pNext;
		}
		else
		{
			newobj->add_term(obj);
			obj = obj->m_pNext;
		}
	}

	//avelacnum  enq  mnacac  ktorner@
	if (obj2 != nullptr)
	{
		while (obj2 != nullptr)
		{
			newobj->add_term(obj2);
			obj2 = obj2->m_pNext;
		}
	}	 
	else if (obj != nullptr)
	{
		while (obj != nullptr)
		{
			newobj->add_term(obj);
			obj = obj->m_pNext;
		}
	}

	obj2 = temp_obj2_root;
	obj=temp_obj_root;
	return *newobj;
}


std::ostream& operator<<(std::ostream& output,const Polynom& obj1)
{
	Node* obj = obj1.m_pRoot;
	Node* temp_ptr = obj;
	while(obj->m_pNext != nullptr)
	{
		if (obj->m_pNext->m_oCoefficient > 0)
		{
			if (obj->m_oCoefficient != 1)
				output << obj->m_oCoefficient << "X^" << obj->m_oExponent << " + ";
			else
				output << "X^" << obj->m_oExponent << " + ";
		}
		else  if (obj->m_oCoefficient != -1)
			output << obj->m_oCoefficient << "X^" << obj->m_oExponent << ' ';
		else
			output << "- X^" << obj->m_oExponent << ' ';

		//araj enq  talis  cucichy
		obj = obj->m_pNext;
	}
	//verjin  tarri  tpum
	if (obj->m_oExponent == 1)
		output << obj->m_oCoefficient << "X";
	else
		output << obj->m_oCoefficient << "X^" << obj->m_oExponent;
	//cucich@  berum enq  skizb
	obj = temp_ptr;

	return output;
}





