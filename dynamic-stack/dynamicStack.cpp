#include "dynamicStack.h"
#include <iostream>

using namespace std;

DynamicStack::DynamicStack() {
  topNode = nullptr;
}

DynamicStack::~DynamicStack() {
  while (topNode != nullptr) {
    Node *TempNode = topNode;

    topNode = topNode->next;

    delete TempNode;
  }
}

void DynamicStack::push(DynamicStackItemType content) {
  if (isFull()) {
    cout << "Memory is full";
  } else {
    Node *NewNode = new Node;

    NewNode->content = content;
    NewNode->next = topNode;

    topNode = NewNode;
  }
}

DynamicStackItemType DynamicStack::pop() {
  if (isEmpty()) {
    cout << "Dynamic stack is empty";
  } else {
    DynamicStackItemType content = topNode->content;
    Node *TempNode = topNode;
    topNode = topNode->next;

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
  return topNode == nullptr;
}

void DynamicStack::print() {
  if (isEmpty()) {

  } else {
    Node *TempNode = topNode;

    cout << "[ ";

    while (TempNode != nullptr) {
      cout << TempNode->content << " ";

      TempNode = TempNode->next;
    }

    cout << "]" << endl;
  }
}