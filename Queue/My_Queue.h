#pragma once
#include "Queue_interface.h"
#include <deque>

template<typename Queue_Object_Type>
class My_Queue :public Queue_interface<Queue_Object_Type>
{
private:
	std::deque<Queue_Object_Type> Queue_Array_Object;

public:
	/*++++++++++++++++++*/

	explicit My_Queue<Queue_Object_Type>():Queue_interface<Queue_Object_Type>(){}

	explicit My_Queue<Queue_Object_Type>(std::initializer_list<Queue_Object_Type> obj): Queue_interface<Queue_Object_Type>()
	{
		try 
		{
			for (const auto& element : obj)
			{
				Queue_Array_Object.push_back(element);
			}
		}
		catch (std::bad_alloc& E)
		{
			E.what();
		}
	}

	virtual ~My_Queue<Queue_Object_Type>() _NOEXCEPT
	{
		if (length() != 0)
			clear();
	}

	/*++++++++++++++++++*/

	virtual void clear() _NOEXCEPT
	{
		Queue_Array_Object.clear();
	}

	virtual void enqueue(const Queue_Object_Type& object)
	{
		try
		{
			Queue_Array_Object.push_back(object);
		}
		catch (std::bad_alloc& E)
		{
			E.what();
		}
	}

	virtual Queue_Object_Type dequeuee() _NOEXCEPT
	{
		if (length() != 0)
		{
			Queue_Object_Type new_obj = Queue_Array_Object.front();
			Queue_Array_Object.pop_front();
			return new_obj;
		}
	}

	virtual const Queue_Object_Type& frontValue() const _NOEXCEPT
	{
		if (length() != 0)
			return Queue_Array_Object.back();
	}

	virtual int length() const _NOEXCEPT
	{
		return Queue_Array_Object.size();
	}
};

