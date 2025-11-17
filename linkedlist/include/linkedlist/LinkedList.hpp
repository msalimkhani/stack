#pragma once
#ifndef __LINKEDLIST_HPP__
#define __LINKEDLIST_HPP__

#include <linkedlist/Node.hpp>
#include <tools/Logger.hpp>

using namespace Tools;

namespace DataStructures
{
  template <typename T>
  class LinkedList
  {
  private:
    Node<T> *head;
    void freeMem(Node<T> *p);
    Node<T> *getLastNode(Node<T> *p);
    Node<T> *getAtPrivate(int index);

  public:
    LinkedList();
    ~LinkedList();

    int getSize();
    void add(T data);

    T getAt(int index);

    void insertAt(int index, T data);

    void insertToBegining(T data);

    void removeAt(int index);

    void print();

    bool isEmpty();

    void clear();

    T* toArray();
  };

#include "LinkedList.tpp"
} // namespace DataStructures

#endif