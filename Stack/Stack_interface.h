#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

template <typename Type>
class Stack_interface
{
private:
	void operator =(const Stack_interface&) {}
	Stack_interface(const Stack_interface&) {}

public:
	Stack_interface(){}
	virtual ~Stack_interface(){}
	virtual void  push(const Type) = 0;
	virtual const Type  pop() = 0;
	virtual const Type&  topValue() = 0; 
	virtual int   length() = 0;
};

#endif // !STACK_INTERFACE_H
