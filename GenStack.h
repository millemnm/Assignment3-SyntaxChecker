#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>
#include <cstdlib>
#include <stdexcept>

//Default capacity for the stack
const int SIZE = 10;

using namespace std;

template <class type>
class GenStack
{
	public:
		GenStack();//constructor
		GenStack(int maxSize);//overloaded constructor
		~GenStack();//destructor

		void push(type d);
		type pop();
		type peek();//aka top()

		bool isFull();
		bool isEmpty();

	private:
		int size;
		int top;

		type *myArray;
};

//default constructor
template <class type>
GenStack<type>::GenStack(){
	size = SIZE;
	myArray = new type[size];
	top = -1;
}

template <class type>
GenStack<type>::GenStack(int maxSize){
	myArray = new type[maxSize];
	size = maxSize;
	top = -1;
}

template <class type>
GenStack<type>::~GenStack(){
	delete[] myArray;
}

template <class type>
void GenStack<type>::push(type d){
	//Create a new longer Array if the old ones full
	if(isFull()){
		type *oldArray = myArray;
		size += SIZE;
		myArray = new type[size];

		for(int i = 0; i <= top; ++i){
			myArray[i] = oldArray[i];
		}
	}

	myArray[++top] = d;
}

template <class type>
type GenStack<type>::pop(){
	//check if its empty
	if(isEmpty()){
		throw std::out_of_range("Stack Underflow");
	}
	return myArray[top--];
}

template <class type>
type GenStack<type>::peek(){
	if(isEmpty()){
		throw std::out_of_range("Stack Underflow");
	}
	return myArray[top];
}

template <class type>
bool GenStack<type>::isFull(){
	return (top == size-1);
}

template <class type>
bool GenStack<type>::isEmpty(){
	return (top == -1);
}

#endif
