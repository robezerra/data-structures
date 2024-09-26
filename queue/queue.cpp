#include "queue.h"
#include <iostream>

using namespace std;

Queue::Queue() {
  front = 0;
  back = 0;
  structure = new QueueItemType[MAX_ITEMS];
}

Queue::~Queue() {
  delete[] structure;
}

void Queue::enqueue(QueueItemType item) {
  if (isFull()) {
    cout << "Queue is already full" << endl;
  } else {
    structure[back % MAX_ITEMS] = item;

    back++;
  }
}

void Queue::dequeue() {
  if (isEmpty()) {
    cout << "There are no items to remove" << endl;
  } else {
    front++;

    structure[front - 1];
  }
}

void Queue::peek() {
  if (isEmpty()) {
    cout << "There are no items in the queue" << endl;
  } else {
    cout << "The element at the front node is: " << structure[front % MAX_ITEMS] << endl;
  }
}

void Queue::rear() {
  if (isEmpty()) {
    cout << "There are no items in the queue" << endl;
  } else {
    cout << "The element at the rear node is: " << structure[back - 1 % MAX_ITEMS] << endl;
  }
}

bool Queue::isEmpty() {
  return front == back;
}

bool Queue::isFull() {
  return back - front == MAX_ITEMS;
}

void Queue::print() {
  cout << "[ ";

  for (int i = front; i < back; i++) {
    cout << structure[i % MAX_ITEMS] << " ";
  }

  cout << "]" << endl;
}