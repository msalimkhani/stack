template <typename T>

Stack<T>::Stack() {
  this->list = new LinkedList<T>();
}

template <typename T> Stack<T>::~Stack() { delete this->list; }

template <typename T>

T Stack<T>::top() {
  return this->list->getAt(0);
}
template <typename T> T Stack<T>::pop() {
  T top = this->top();
  this->list->removeAt(0);
  return top;
}

template <typename T>

void Stack<T>::push(T item) {
  this->list->insertToBegining(item);
}