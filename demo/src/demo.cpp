#include <Stack.hpp>
#include <iostream>
#include <ostream>

using namespace DataStructures;

int main()
{
    Logger::get().log(Logger::INFO, "LinkedList:");
    LinkedList<char> list;

    try
    {
        list.add('m');
        list.add('a');
        list.print();
        list.add('j');
        list.add('h');
        list.add('l');
        list.add('i');
        list.print();
        list.removeAt(2);
        list.print();
        list.removeAt(3);
        list.print();
        list.insertAt(2, 'd');
        list.print();
    }
    catch (const std::exception &e)
    {
        Logger::get().log(Logger::ERROR, e.what());
    }

    Stack<int> stack;
    Logger::get().log(Logger::INFO, "Stack:");
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.print();
    std::cout << "top : " << stack.top() << " pop : " << stack.pop() << std::endl;
    stack.print();
    stack.push(4);
    stack.push(5);
    stack.print();
    std::cout << "size : " << stack.getSize() << std::endl;
    std::cout << "popping all elements: ";
    std::cout << stack.pop() << " " << stack.pop() << " " << stack.pop() << " " << stack.pop() << std::endl;
    stack.print();
    return 0;
}