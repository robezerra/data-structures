#include "stack.h"
#include <iostream>

using namespace std;

int main() {
  Stack stack;

  StackItemType item;
  int choice = 0;

  do {
    cout << "Type 0 to quit" << endl;
    cout << "Type 1 to add one item" << endl;
    cout << "Type 2 to remove one item" << endl;
    cout << "Type 3 to print the stack" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Insert a number: " << endl;
      cin >> item;
      stack.insert(item);

      break;

    case 2:
      stack.remove();

      break;
    case 3:
      stack.print();

      break;
    default:
      break;
    }
  } while (choice != 0);

  return 0;
}