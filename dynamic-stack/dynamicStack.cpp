#include "dynamicStack.h"
#include <iostream>

using namespace std;

DynamicStack::DynamicStack() {
  TopNode = nullptr;
}

DynamicStack::~DynamicStack() {
  while (TopNode != nullptr) {
    Node *TempNode = TopNode;

    TopNode = TopNode->next;

    delete TempNode;
  }
}

void DynamicStack::insert(DynamicStackItemType content) {
  if (isFull()) {
    cout << "Memory is full";
  } else {
    Node *NewNode = new Node;

    NewNode->content = content;
    NewNode->next = TopNode;

    TopNode = NewNode;
  }
}

DynamicStackItemType DynamicStack::remove() {
  if (isEmpty()) {
    cout << "Dynamic stack is empty";
  } else {
    DynamicStackItemType content = TopNode->content;
    Node *TempNode = TopNode;
    TopNode = TopNode->next;

    delete TempNode;

    return content;
  }
}

bool DynamicStack::isFull() {
  try {
    Node *NewNode = new Node;

    delete NewNode;

    return false;
  } catch (bad_alloc exception) {
    return true;
  }
}

bool DynamicStack::isEmpty() {
  return TopNode == nullptr;
}

void DynamicStack::print() {
  if (isEmpty()) {

  } else {
    Node *TempNode = TopNode;

    cout << "[ ";

    while (TempNode != nullptr) {
      cout << TempNode->content << " ";

      TempNode = TempNode->next;
    }

    cout << "]" << endl;
  }
}