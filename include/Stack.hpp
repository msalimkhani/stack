#pragma once
#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <linkedlist/LinkedList.hpp>

namespace DataStructures
{
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
		void print(){
			this->list->print();
		}
		int getSize(){
			return this->list->getSize();
		}
};

#include "Stack.tpp"
} // namespace DataStructures


#endif
