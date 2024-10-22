#include "hash.h"
#include <iostream>

using namespace std;

int main() {
  Student student(-1, " ");

  int userChoice, studentCode;
  string studentName;
  bool isFind;

  int hashTableSize, hashTableMaxSize;

  do {
    cout << "Type the max size of the hash table\n";
    cin >> hashTableMaxSize;

    if (hashTableSize < 2) {
      cout << "Hash table size should be greater than 1\n";
    }
  } while (hashTableSize < 2);

  do {
    cout << "Type the size of the hash table\n";
    cin >> hashTableSize;

    if (hashTableSize >= hashTableMaxSize) {
      cout << "Hash table size should be less than max size\n";
    }
  } while (hashTableSize >= hashTableMaxSize);

  cout
      << "The load factor is: " << (float)hashTableMaxSize / (float)hashTableSize << endl;

  Hash hashTable(hashTableSize, hashTableMaxSize);

  do {
    cout << "Type 0 to quit\n";
    cout << "Type 1 to add an item\n";
    cout << "Type 2 to remove an item\n";
    cout << "Type 3 to search an item\n";
    cout << "Type 4 to print the hash table\n";
    cin >> userChoice;
    switch (userChoice) {
    case 1:
      cout << "Insert the student code:\n";
      cin >> studentCode;
      cout << "Insert the student name:\n";
      cin >> studentName;

      student = Student(studentCode, studentName);
      hashTable.insert(student);
      break;
    case 2:
      cout << "Insert the student code:\n";
      cin >> studentCode;
      cout << "Insert the student name:\n";
      cin >> studentName;

      student = Student(studentCode, studentName);

      hashTable.remove(student);

      break;
    case 3:
      cout << "Insert the student code:\n";
      cin >> studentCode;

      cout << "Insert the student name:\n";
      cin >> studentName;

      student = Student(studentCode, studentName);

      hashTable.search(student, isFind);

      if (isFind) {
        cout << "Student found:\n";
        cout << "Code: " << student.getCode() << endl;
        cout << "Name: " << student.getName() << endl;
      } else {
        cout << "Student not found\n";
      }

      break;
    case 4:
      hashTable.print();
    }
  } while (userChoice != 0);

  return 0;
}
