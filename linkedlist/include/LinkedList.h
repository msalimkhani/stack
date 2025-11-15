#pragma once
#include "Node.h"

#ifdef _WIN32
#ifdef LINKEDLIST_EXPORTS
#define LINKEDLIST_API __declspec(dllexport)
#else
#define LINKEDLIST_API __declspec(dllimport)
#endif
#else
#define LINKEDLIST_API
#endif
template <typename T> class LINKEDLIST_API LinkedList {
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