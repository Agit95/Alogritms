#pragma once
#include <algorithm>


template<typename T>
class Heap
{
private:
	int m_capacity;
	int m_size;
	T*  m_data;

public:
	//ctor  By Default
	Heap() :m_capacity(32), m_size(0)
	{
		m_data = new T[m_capacity];
	}

	Heap(std::initializer_list<T> element):Heap()
	{
		for (auto obj : element)
		{
			insert(obj);
		}
	}

	//Destructor
	~Heap()
	{
		delete[] m_data;
	}

	//function Root returned  Root index HeapTree
	T  Root()	_NOEXCEPT
	{
		if (size() != 1)
		{
			std::swap(m_data[0], m_data[size() - 1]);
			T temp_obj = m_data[size() - 1];
			m_data[size() - 1] = 0;
			--m_size;
			heapify(0);
			return temp_obj;
		}
		else
		{
			T   temp_object = m_data[0];
			m_data[0] = 0;
			--m_size;
			return	temp_object;
		}
	}


	//function Left returned Left node index selectoin  Root   
	int Left(int index)	  _NOEXCEPT
	{
		return 2 * index;
	}

	//returned  reight node index selection Root
	int Reight(int index)  _NOEXCEPT
	{
		return 2 * index + 1;
	}

	//function size  returned  size  of the HeapTree
	int size()	 _NOEXCEPT
	{
		return m_size;
	}

	//function isEmpti returned  HeapTree  is Empti  or  not
	bool isEmpti()	_NOEXCEPT
	{
		return m_size == 0;
	}

	//function Heapify  corrected  there array
	void heapify(int index)
	{
		int l = 0;
		int r = 0;
		if (Left(index) != 0)
			l = Left(index);
		if (Reight(index) != 0)
			r = Reight(index);

		int maximum_index = index;
		
		if (Left(index) > 0)
		{
			if (m_data[maximum_index] < m_data[l])
				maximum_index = l;
		}
		if (Reight(index) > 0)
		{
			if (m_data[maximum_index] < m_data[r])
				maximum_index = r;
		}
		if (index != maximum_index)
		{
			std::swap(m_data[index], m_data[maximum_index]);
			heapify(maximum_index);
		}
	}

	//building  Heap  
	void build_heap()
	{
		for (int i = size() / 2 + 1; i >= 0; --i)
		{
			heapify(i);
		}
	}

	//function insert
	void insert(T value)
	{
		m_data[size()] = value;
		++m_size;

		//correcting array  
		build_heap();

		if (m_size == m_capacity)
			enlarge();
	}

	//if capacity == size  enlarge  heap
	void enlarge()
	{
		T* temp_data(m_data);
		m_capacity *= 2;
		m_data = new T[m_capacity];
		for (unsigned int i = 0; i < size(); ++i)
			m_data[i] = temp_data[i];
		delete[] temp_data;
	}



};

