#include "linkedList.h"
#include <iostream>

using namespace std;

typedef int LinkedListItemType;

int main() {
  LinkedList<LinkedListItemType> linkedList;
  LinkedListItemType content;

  int userChoice = 0;

  do {
    cout << "Type 0 to quit" << endl;
    cout << "Type 1 to add a content" << endl;
    cout << "Type 2 to remove a content" << endl;
    cout << "Type 3 to print the linked list" << endl;
    cin >> userChoice;

    switch (userChoice) {
    case 1:
      cout << "Insert a number: " << endl;
      cin >> content;
      linkedList.enqueue(content);

      break;

    case 2:
      content = linkedList.dequeue();

      cout << "Removed content: " << content << endl;

      break;
    case 3:
      linkedList.print();

      break;
    default:
      break;
    }
  } while (userChoice != 0);

  return 0;
}