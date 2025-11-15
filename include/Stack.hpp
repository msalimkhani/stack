#pragma once
#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <LinkedList.h>

template <typename T>

class Stack{
	private:
		LinkedList<T> *list;
	public:
		Stack();
		~Stack();
		T top();
		T pop();
		void push(T item);

		int getSize(){
			return this->list->getSize();
		}
};

#include "../src/Stack.tpp"

#endif
