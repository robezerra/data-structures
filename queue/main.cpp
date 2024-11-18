#include "queue.h"
#include <iostream>

using namespace std;

int main() {
  Queue queue;

  QueueItemType item;
  int userChoice = 0;

  do {
    cout << "Type 0 to quit" << endl;
    cout << "Type 1 to add a item" << endl;
    cout << "Type 2 to pop a item" << endl;
    cout << "Type 3 to print the element at the front node" << endl;
    cout << "Type 4 to print the element at the back node" << endl;
    cout << "Type 5 to print all elements of the queue" << endl;
    cin >> userChoice;

    switch (userChoice) {
    case 1:
      cout << "Insert a number: " << endl;
      cin >> item;

      queue.enqueue(item);

      break;
    case 2:
      queue.dequeue();

      break;
    case 3:
      queue.peek();

      break;
    case 4:
      queue.rear();

      break;
    case 5:
      queue.print();

      break;
    default:
      break;
    }
  } while (userChoice != 0);

  return 0;
}