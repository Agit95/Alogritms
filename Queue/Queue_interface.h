#pragma once

template <typename Type>
class Queue_interface
{
private: 
	void  operator =(const Queue_interface&);
	Queue_interface(const Queue_interface&);

public:

	Queue_interface<Type>() {}				//ctor by default
	virtual ~Queue_interface<Type>() {}		//~ctor 

	virtual void clear() = 0;  
	virtual void enqueue(const Type&) = 0;
	virtual Type dequeuee() = 0;
	virtual const Type& frontValue() const = 0;
	virtual int length() const = 0;
};
