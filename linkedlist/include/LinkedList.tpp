#include <iostream>
#include <ostream>
template <typename T>

LinkedList<T>::LinkedList() {
  this->head = new Node<T>();
  this->head->next = nullptr;
}

template <typename T> LinkedList<T>::~LinkedList() {
  if (head != nullptr) {
    this->freeMem(this->head);
  }
}

template <typename T>

void LinkedList<T>::freeMem(Node<T> *p) {
  if (p == nullptr)
    return;
  this->freeMem(p->next);
  delete p;
}

template <typename T> Node<T> *LinkedList<T>::getLastNode(Node<T> *p) {
  if (p->next == nullptr)
    return p;
  return this->getLastNode(p->next);
}

template <typename T>

Node<T> *LinkedList<T>::getAtPrivate(int index) {
  Node<T> *p = this->head;
  for (int i = 0; i < index; i++) {
    p = p->next;
  }
  return p;
}

template <typename T> void LinkedList<T>::add(T data) {
  Node<T> *lastNode = this->getLastNode(this->head);
  if (lastNode != nullptr) {
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
    lastNode->next = newNode;
    this->count++;
  }
}
template <typename T> T LinkedList<T>::getAt(int index) {
  Node<T> *p = this->getAtPrivate(index);
  if (p != nullptr) {
    return p->data;
  }

  return T{};
}
template <typename T> void LinkedList<T>::insertAt(int index, T data) {
  Node<T> *p = this->getAtPrivate(index);
  if (p != nullptr) {
    Node<T> *nn = new Node<T>();
    nn->data = data;
    nn->next = p->next;
    p->next = nn;
    this->count++;
  }
}
template <typename T> void LinkedList<T>::removeAt(int index) {
  Node<T> *p = head;
  if(index == 0){
    this->head = p->next;
    delete p;
  }
  for (int i = 0; i < index; i++)
    p = p->next;
  if (p != nullptr && p->next != nullptr)
    p->next = p->next->next;

  this->count--;
}

template <typename T> int LinkedList<T>::getSize(){
  return this->count;
}

template<typename T>
void LinkedList<T>::insertToBegining(T item){
  Node<T> *n = new Node<T>();
  n->data = item;
  n->next = this->head;
  this->head = n;
}