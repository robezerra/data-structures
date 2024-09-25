#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack() {
  stackLength = 0;
  stackStructure = new TypeStackItem[MAX_ITEMS];
}

Stack::~Stack() {
  delete[] stackStructure;
}

void Stack::insert(TypeStackItem item) {
  if (isFull()) {
    cout << "Stack is already full" << endl;
  } else {
    stackStructure[stackLength] = item;

    stackLength++;
  }
}

TypeStackItem Stack::remove() {
  if (stackLength > 0) {
    --stackLength;
    return stackStructure[stackLength];
  } else {
    cout << "There are no items in the stack" << endl;

    return 0;
  }
}

void Stack::print() {
  if (stackLength > 0) {
    cout << "[";

    for (int i = 0; i < stackLength; i++) {
      cout << stackStructure[i] << " ";
    }

    cout << "]" << endl;
    ;
  } else {
    cout << "There are no items in the stack" << endl;
  }
}

bool Stack::isFull() {
  return stackLength == MAX_ITEMS;
}

bool Stack::isEmpty() {
  return stackLength == 0;
}

int Stack::lenght() {
  return stackLength;
}