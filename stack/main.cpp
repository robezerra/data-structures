#include "stack.h"
#include <iostream>

using namespace std;

int main() {
  Stack stack;
  StackItemType item;

  int userChoice = 0;

  do {
    cout << "Type 0 to quit" << endl;
    cout << "Type 1 to add a item" << endl;
    cout << "Type 2 to remove a item" << endl;
    cout << "Type 3 to print the stack" << endl;
    cin >> userChoice;

    switch (userChoice) {
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
  } while (userChoice != 0);

  return 0;
}