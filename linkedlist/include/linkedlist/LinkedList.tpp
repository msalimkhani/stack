using namespace DataStructures;

template <typename T>
LinkedList<T>::LinkedList()
{
  this->head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  try
  {
    if (head != nullptr)
    {
      this->freeMem(this->head);
    }
  }
  catch (const std::exception &ex)
  {
    Logger::get().log(Logger::ERROR,
                      "Exception in LinkedList destructor: " +
                          std::string(ex.what()));
  }
}

template <typename T>

void LinkedList<T>::freeMem(Node<T> *p)
{
  try
  {
    if (p == nullptr)
      return;
    this->freeMem(p->next);
    delete p;
  }
  catch (const std::exception &e)
  {
    Logger::get().log(Logger::ERROR,
                      "Exception in LinkedList freeMem: " +
                          std::string(e.what()));
  }
}

template <typename T>
Node<T> *LinkedList<T>::getLastNode(Node<T> *p)
{
  try
  {
    if(p == nullptr)
    {
      return p;
    }

    if (p->next == nullptr)
    {
      return p;
    }
    return this->getLastNode(p->next);
  }
  catch (const std::exception &e)
  {
    Logger::get().log(Logger::ERROR,
                      "Exception in LinkedList getLastNode: " +
                          std::string(e.what()));
    return nullptr;
  }
}

template <typename T>

Node<T> *LinkedList<T>::getAtPrivate(int index)
{
  try
  {
    Node<T> *p = this->head;
    for (int i = 0; i < index; i++)
    {
      p = p->next;
    }
    return p;
  }
  catch (const std::exception &e)
  {
    Logger::get().log(Logger::ERROR,
                      "Exception in LinkedList getAtPrivate: " +
                          std::string(e.what()));
    return nullptr;
  }
}

template <typename T>
void LinkedList<T>::add(T data)
{
  try
  {
    Node<T> *lastNode = this->getLastNode(this->head);
    if (lastNode != nullptr)
    {
      Node<T> *newNode = new Node<T>();
      newNode->data = data;
      lastNode->next = newNode;
    }
    else{
      lastNode = new Node<T>();
      lastNode->data = data;
      lastNode->next = nullptr;
      this->head = lastNode;
    }
  }
  catch (const std::exception &e)
  {
    Logger::get().log(Logger::ERROR,
                      "Exception in LinkedList add: " +
                          std::string(e.what()));
  }
}
template <typename T>
T LinkedList<T>::getAt(int index)
{
  try
  {
    Node<T> *p = this->getAtPrivate(index);
    if (p != nullptr)
    {
      return p->data;
    }

    return T{};
  }
  catch (const std::exception &e)
  {
    Logger::get().log(Logger::ERROR,
                      "Exception in LinkedList getAt: " +
                          std::string(e.what()));
    return T{};
  }
}
template <typename T>
void LinkedList<T>::insertAt(int index, T data)
{
  try
  {
    Node<T> *p = this->getAtPrivate(index);
    if (p != nullptr)
    {
      Node<T> *nn = new Node<T>();
      nn->data = data;
      nn->next = p->next;
      p->next = nn;
    }
  }
  catch (const std::exception &e)
  {
    Logger::get().log(Logger::ERROR,
                      "Exception in LinkedList insertAt: " +
                          std::string(e.what()));
  }
}
template <typename T>
void LinkedList<T>::removeAt(int index)
{
  try
  {
    if(index == 0){
      if(this->head != nullptr)
      {
        if(this->head->next == nullptr){
          Node<T> *toDel = this->head;
          this->head = nullptr;
          delete toDel;
          return;
        }

        Node<T> *toDel = this->head;
        this->head = this->head->next;
        delete toDel;
      }
      return;
    }
    Node<T> *p = this->getAtPrivate(index - 1);
    if (p != nullptr && p->next != nullptr)
    {
      Node<T> *toDelete = p->next;
      p->next = toDelete->next;
      delete toDelete;
    }
  }
  catch (const std::exception &e)
  {
    Logger::get().log(Logger::ERROR,
                      "Exception in LinkedList removeAt: " +
                          std::string(e.what()));
  }
}

template <typename T>
int LinkedList<T>::getSize()
{
  int count = 0;

  Node<T> *p = this->head;
  while (true)
  {
    if (p == nullptr)
    {
      break;
    }
    count++;
    if(p->next == nullptr)
    {
      break;
    }

    p = p->next;
  }

  return count;
}

template <typename T>
void LinkedList<T>::insertToBegining(T item)
{
  try
  {
    Node<T> *n = new Node<T>();
    n->data = item;
    n->next = this->head;
    this->head = n;
  }
  catch (const std::exception &e)
  {
    Logger::get().log(Logger::ERROR,
                      "Exception in LinkedList insertToBegining: " +
                          std::string(e.what()));
  }
}

template <typename T>
void LinkedList<T>::print()
{
  try
  {
    Node<T> *p = this->head;
    while (p != nullptr)
    {
      std::cout << p->data << " ";
      p = p->next;
    }
    std::cout << std::endl;
  }
  catch (const std::exception &e)
  {
    Logger::get().log(Logger::ERROR,
                      "Exception in LinkedList toArray: " +
                          std::string(e.what()));
  }
}

template <typename T>
T *LinkedList<T>::toArray()
{
  try
  {
    int size = this->getSize();

    T *retArr = (T *)malloc(size * sizeof(T));
    if (retArr <= 0)
    {
      Logger::get().log(Logger::ERROR, "Memory Allocation Failed");
      return nullptr;
    }

    if (this->isEmpty())
    {
      Logger::get().log(Logger::WARNING, "LinkedList is empty");
    }
    else
    {
      Node<T> *p = this->head;
      int index = 0;
      while (p != nullptr && index < size)
      {
        retArr[index] = p->data;
        p = p->next;
        index++;
      }
    }

    return retArr;
  }
  catch (const std::exception &e)
  {
    Logger::get().log(Logger::ERROR,
                      "Exception in LinkedList toArray: " +
                          std::string(e.what()));
    return nullptr;
  }
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
  return this->head == nullptr || this->head->data != T{};
}

template <typename T>
void LinkedList<T>::clear()
{
  try
  {
    this->freeMem(this->head);
    this->head = nullptr;
  }
  catch (const std::exception &e)
  {
    Logger::get().log(Logger::ERROR,
                      "Exception in LinkedList clear: " +
                          std::string(e.what()));
  }
}
