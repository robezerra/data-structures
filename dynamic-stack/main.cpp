#include "dynamicStack.h"
#include <iostream>

using namespace std;

int main() {
  DynamicStack stack;
  DynamicStackItemType content;

  int userChoice = 0;

  do {
    cout << "Type 0 to quit" << endl;
    cout << "Type 1 to add a content" << endl;
    cout << "Type 2 to remove a content" << endl;
    cout << "Type 3 to print the stack" << endl;
    cin >> userChoice;

    switch (userChoice) {
    case 1:
      cout << "Insert a number: " << endl;
      cin >> content;
      stack.insert(content);

      break;

    case 2:
      content = stack.remove();

      cout << "Removed content: " << content << endl;

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