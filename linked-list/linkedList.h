#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
struct Node {
  T content;
  Node<T> *next;
};

template <typename T>
class LinkedList {
private:
  Node<T> *head, *tail;

public:
  LinkedList();
  ~LinkedList();

  void enqueue(T content);
  T dequeue();
  bool isFull();
  bool isEmpty();
  void print();
};

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
    std::cout << "Memory is full\n";
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
    std::cout << "Linked list is empty\n";

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
  } catch (std::bad_alloc &ex) {
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
  std::cout << "[ ";

  while (temp != nullptr) {
    std::cout << temp->content << " ";
    temp = temp->next;
  }

  std::cout << "]\n";
}

#endif
