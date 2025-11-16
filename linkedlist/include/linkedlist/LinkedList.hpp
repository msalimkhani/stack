#pragma once
#include <linkedlist/Node.hpp>
#include <tools/Logger.hpp>

template <typename T> class LinkedList {
private:
  Node<T> *head;
  int count = 0;
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
};

#include "LinkedList.tpp"