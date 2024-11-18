#include "student.h"

struct Node {
  Student student;
  Node *leftChild;
  Node *rightChild;
};

class BST {
private:
  Node *root;

public:
  BST();
  ~BST();
  void push(Student student);
  bool search(Student student);
  void deleteTree(Node *node);
  void pop(Student student);
  void searchDelete(Student student, Node *&currentNode);
  void deleteNode(Node *&currentNode);
  void getSuccessor(Student &successorStudent, Node *tempNode);
  Node *getRoot();
  bool isFull();
  bool isEmpty();
  void preOrder(Node *node);
  void inOrder(Node *node);
  void postOrder(Node *node);
  void mirror(Node *node);
};
