#include "hash.h"

using namespace std;

Hash::Hash(int maxItems, int maxSize) {
  itemsQuantity = 0;
  MAX_ITEMS = maxItems;
  MAX_SIZE = maxSize;
  structure = new Student[maxSize];
}

Hash::~Hash() {
  delete[] structure;
}

int Hash::hashFunction(Student student) {
  return student.getCode() % MAX_SIZE;
}

void Hash::push(Student student) {
  if (!isFull()) {
    int position = hashFunction(student);

    while (structure[position].getCode() > 0) {
      position = (position + 1) % MAX_SIZE;
    }

    structure[position] = student;
    itemsQuantity++;
  } else {
    cout << "Hash table is already full\n";
  }
}

void Hash::pop(Student student) {
  bool isDeleted = false;

  if (itemsQuantity > 0) {
    int position = hashFunction(student);

    while (structure[position].getCode() != -1) {
      if (structure[position].getCode() == student.getCode()) {
        structure[position] = Student(-2, " ");

        itemsQuantity--;
        isDeleted = true;

        cout << "Element deleted!\n";

        break;
      }

      position = (position + 1) % MAX_SIZE;
    }
  }

  if (!isDeleted) {
    cout << "Student not found\n";
  }
}

void Hash::search(Student &student, bool &isFound) {
  int position = hashFunction(student);

  while (structure[position].getCode() != -1 && position != MAX_SIZE) {
    if (structure[position].getCode() == student.getCode()) {

      isFound = true;
      student = structure[position];

      break;
    }

    position = (position + 1) % MAX_SIZE;
  }
}

void Hash::print() {
  cout << "Hash Table:\n";

  for (int i = 0; i < MAX_SIZE; i++) {
    if (structure[i].getCode() > 0) {
      cout << i << ": " << structure[i].getCode() << ", " << structure[i].getName() << endl;
    }
  }
}

bool Hash::isFull() {
  return itemsQuantity == MAX_ITEMS;
}

bool Hash::isEmpty() {
  return itemsQuantity == 0;
}

int Hash::getCurrentSize() {
  return itemsQuantity;
}