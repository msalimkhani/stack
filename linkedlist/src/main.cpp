#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
  cout << "ok" << endl;
  LinkedList<int> list;
  list.add(1);
  list.add(2);
  list.add(3);
  list.insertAt(1, 5);
  list.removeAt(2);
  cout << list.getAt(0) << 
  " " << list.getAt(2) << 
  " " << list.getAt(1) << 
  " " << list.getSize() << endl;
  return 0;
}
