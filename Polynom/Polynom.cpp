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
	Polynom& obj2 = const_cast<Polynom&>(obj3);
	Polynom& obj = const_cast<Polynom&>(obj1);
	Node* temp_obj_root = obj.m_pRoot;
	Node* temp_obj2_root = obj2.m_pRoot;
	while (obj2.m_pRoot != nullptr && obj.m_pRoot != nullptr)
	{
		if (obj2.m_pRoot->m_oExponent == obj.m_pRoot->m_oExponent)
		{
			obj2.m_pRoot->m_oCoefficient -= obj.m_pRoot->m_oCoefficient;
			obj2.m_pRoot = obj2.m_pRoot->m_pNext;
			obj.m_pRoot = obj.m_pRoot->m_pNext;
		}
		else if (obj2.m_pRoot->m_oExponent > obj.m_pRoot->m_oExponent)
		{
			//poxum enq  nshan@ vorovhetev   nshani popoxutyun  e  linelu
			obj.m_pRoot->m_oCoefficient = -obj.m_pRoot->m_oCoefficient;

			obj2.add_term(obj.m_pRoot);
			//obyect@  berum enq  naxkin vichakin
			obj.m_pRoot->m_oCoefficient = -obj.m_pRoot->m_oCoefficient;
			obj.m_pRoot = obj.m_pRoot->m_pNext;
		}
		else
		{
			//poxum enq  nshan@ vorovhetev   n\ani popoxutyun  e  linelu
			obj.m_pRoot->m_oCoefficient = -obj.m_pRoot->m_oCoefficient;

			obj2.add_term(obj.m_pRoot);
			//obyect@  berum enq  naxkin vichakin
			obj.m_pRoot->m_oCoefficient = -obj.m_pRoot->m_oCoefficient;
			obj.m_pRoot = obj.m_pRoot->m_pNext;
		}
	}
	obj2.m_pRoot = temp_obj2_root;
	obj.m_pRoot = temp_obj_root;
	return  obj2;
}

const Polynom& operator +(const Polynom& obj3,const Polynom& obj1)
{
	Polynom& obj2 = const_cast<Polynom&>(obj3);
	Polynom& obj = const_cast<Polynom&>(obj1);
	Node* temp_obj2_root = obj2.m_pRoot;
	Node* temp_obj_root = obj.m_pRoot;
	while (obj.m_pRoot != nullptr && obj2.m_pRoot != nullptr)
	{
		if (obj.m_pRoot->m_oExponent == obj2.m_pRoot->m_oExponent)
		{
			obj.m_pRoot->m_oCoefficient += obj2.m_pRoot->m_oCoefficient;
			obj.m_pRoot = obj.m_pRoot->m_pNext;
			obj2.m_pRoot = obj2.m_pRoot->m_pNext;
		}
		else if (obj.m_pRoot->m_oExponent > obj2.m_pRoot->m_oExponent)
		{
			obj.add_term(obj2.m_pRoot);
			obj2.m_pRoot = obj2.m_pRoot->m_pNext;
		}
		else
		{
			obj.add_term(obj2.m_pRoot);
			obj2.m_pRoot = obj2.m_pRoot->m_pNext;
		}
	}
	obj2.m_pRoot = temp_obj2_root;
	obj.m_pRoot=temp_obj_root;
	return obj;
}


std::ostream& operator<<(std::ostream& output,const Polynom& obj1)
{
	Polynom& obj = const_cast<Polynom&>(obj1);
	Node* temp_ptr = obj.m_pRoot;
	while(obj.m_pRoot->m_pNext != nullptr)
	{
		if (obj.m_pRoot->m_pNext->m_oCoefficient > 0)
		{
			if (obj.m_pRoot->m_oCoefficient != 1)
				output << obj.m_pRoot->m_oCoefficient << "X^" << obj.m_pRoot->m_oExponent << " + ";
			else
				output << "X^" << obj.m_pRoot->m_oExponent << " + ";
		}
		else  if (obj.m_pRoot->m_oCoefficient != -1)
			output << obj.m_pRoot->m_oCoefficient << "X^" << obj.m_pRoot->m_oExponent << ' ';
		else
			output << "- X^" << obj.m_pRoot->m_oExponent << ' ';

		//araj enq  talis  cucichy
		obj.m_pRoot = obj.m_pRoot->m_pNext;
	}
	//verjin  tarri  tpum
	if (obj.m_pRoot->m_oExponent == 1)
		output << obj.m_pRoot->m_oCoefficient << "X";
	else
		output << obj.m_pRoot->m_oCoefficient << "X^" << obj.m_pRoot->m_oExponent;
	//cucich@  berum enq  skizb
	obj.m_pRoot = temp_ptr;

	return output;
}





