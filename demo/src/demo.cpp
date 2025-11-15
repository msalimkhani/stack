#include <Stack.hpp>
#include <iostream>
#include <ostream>

int main(){
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "top : " << stack.top() << " " << stack.pop() << std::endl;
    stack.push(4);
    stack.push(5);
    std::cout << stack.pop() << " " <<stack.pop() << " " << stack.pop() << std::endl;
    
    return 0;
}