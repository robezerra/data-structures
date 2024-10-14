#include "linkedList.h"
#include <iostream>

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() {
  head = nullptr;
  tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
  Node<T> *temp;

  while (head != nullptr) {
    temp = head;

    head = head->next;

    delete temp;
  }

  tail = nullptr;
}

template <typename T>
void LinkedList<T>::enqueue(T content) {
  if (isFull()) {
    cout << "Memory is full\n";
  } else {
    Node<T> *newNode = new Node<T>;

    newNode->content = content;
    newNode->next = nullptr;

    if (isEmpty()) {
      head = newNode;
    } else {
      tail->next = newNode;
    }

    tail = newNode;
  }
}

template <typename T>
T LinkedList<T>::dequeue() {
  if (isEmpty()) {
    cout << "Linked list is empty\n";

    return T();
  } else {
    Node<T> *temp = head;

    T removedContent = head->content;
    head = head->next;

    if (head == nullptr) {
      tail = nullptr;
    }

    delete temp;

    return removedContent;
  }
}

template <typename T>
bool LinkedList<T>::isFull() {
  try {
    Node<T> *temp = new Node<T>;

    delete temp;

    return false;
  } catch (bad_alloc ex) {
    return true;
  }
}

template <typename T>
bool LinkedList<T>::isEmpty() {
  return (head == nullptr);
}

template <typename T>
void LinkedList<T>::print() {
  Node<T> *temp = head;

  cout << "[ ";
  while (temp != nullptr) {
    cout << temp->content << " ";
    temp = temp->next;
  }
  cout << "]\n";
}