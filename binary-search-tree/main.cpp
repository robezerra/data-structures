#include "binarySearchTree.h"
#include <iostream>

using namespace std;

int main() {
  BST bst;
  Student student;

  int userChoice, studentCode;
  string studentName;
  bool isFind;

  do {
    cout << "Type 0 to quit\n";
    cout << "Type 1 to add an item\n";
    cout << "Type 2 to pop an item\n";
    cout << "Type 3 to search an item\n";
    cout << "Type 4 to print the BST\n";
    cin >> userChoice;

    switch (userChoice) {
    case 1:
      cout << "Insert the student code:\n";
      cin >> studentCode;
      cout << "Insert the student name:\n";
      cin >> studentName;

      student = Student(studentCode, studentName);
      bst.push(student);

      break;
    case 2:
      cout << "Insert the student code:\n";
      cin >> studentCode;
      cout << "Insert the student name:\n";
      cin >> studentName;

      student = Student(studentCode, studentName);

      bst.pop(student);

      break;
    case 3:
      cout << "Insert the student code:\n";
      cin >> studentCode;

      cout << "Insert the student name:\n";
      cin >> studentName;

      student = Student(studentCode, studentName);

      bst.search(student);

      if (isFind) {
        cout << "Student found:\n";
        cout << "ID: " << student.getCode() << endl;
        cout << "Name: " << student.getName() << endl;
      } else {
        cout << "Student not found\n";
      }

      break;
    case 4:
      int printChoice;

      cout << "Type 0 to print in pre order\n";
      cout << "Type 1 to print in order\n";
      cout << "Type 2 to print in post order\n";
      cin >> printChoice;

      if (printChoice == 0) {
        bst.preOrder(bst.getRoot());
      } else if (printChoice == 1) {
        bst.inOrder(bst.getRoot());
      } else {
        bst.postOrder(bst.getRoot());
      }

      break;
    }
  } while (userChoice != 0);

  return 0;
}
