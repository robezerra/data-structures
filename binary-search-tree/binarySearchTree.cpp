#include "binarySearchTree.h"

using namespace std;

BST::BST() {
  root = nullptr;
};

BST::~BST() {
  deleteTree(root);
};

void BST::push(Student student) {
  if (isFull()) {
    cout << "Binary search tree is already full\n";
  } else {
    Node *newNode = new Node;

    newNode->student = student;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;

    if (root == nullptr) {
      root = newNode;
    } else {
      Node *tempNode = root;

      while (tempNode != nullptr) {
        if (student.getCode() < tempNode->student.getCode()) {
          if (tempNode->leftChild == nullptr) {
            tempNode->leftChild = newNode;

            break;
          } else {
            tempNode = tempNode->leftChild;
          }
        } else {
          if (tempNode->rightChild == nullptr) {
            tempNode->rightChild = newNode;

            break;
          } else {
            tempNode = tempNode->rightChild;
          }
        }
      }
    }
  }
};

bool BST::search(Student student) {
  if (isEmpty()) {
    cout << "BST is empty\n";
  } else {
    Node *currentNode = root;
    bool isFound = false;

    while (currentNode != nullptr) {
      if (student.getCode() < currentNode->student.getCode()) {
        currentNode = currentNode->leftChild;
      } else if (student.getCode() > currentNode->student.getCode()) {
        currentNode = currentNode->rightChild;
      } else {
        student = currentNode->student;
        isFound = true;

        break;
      }
    }

    return isFound;
  }
};

void BST::deleteTree(Node *node) {
  if (node != nullptr) {
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);

    delete node;
  }
};

void BST::pop(Student student) {
  searchDelete(student, root);
};

void BST::searchDelete(Student student, Node *&currentNode) {
  if (isEmpty()) {
    cout << "BST is empty\n";
  } else {
    if (student.getCode() < currentNode->student.getCode()) {
      searchDelete(student, currentNode->leftChild);
    } else if (student.getCode() > currentNode->student.getCode()) {
      searchDelete(student, currentNode->rightChild);
    } else {
      deleteNode(currentNode);
    }
  }
}

void BST::deleteNode(Node *&currentNode) {
  Node *tempNode = currentNode;

  if (currentNode->leftChild == nullptr) {
    currentNode = currentNode->rightChild;

    delete tempNode;
  } else if (currentNode->rightChild == nullptr) {
    currentNode = currentNode->leftChild;

    delete tempNode;
  } else {
    Student successorStudent;

    getSuccessor(successorStudent, tempNode);

    currentNode->student = successorStudent;

    searchDelete(successorStudent, currentNode->rightChild);
  }
}

void BST::getSuccessor(Student &successorStudent, Node *tempNode) {
  tempNode = tempNode->rightChild;

  while (tempNode->leftChild != nullptr) {
    tempNode = tempNode->leftChild;
  }

  successorStudent = tempNode->student;
}

Node *BST::getRoot() {
  return root;
};

bool BST::isFull() {
  try {
    Node *newNode = new Node;
    delete newNode;

    return false;
  } catch (bad_alloc exception) {
    return true;
  }
};

bool BST::isEmpty() {
  return root == nullptr;
};

void BST::preOrder(Node *node) {
  if (node != nullptr) {
    cout << node->student.getCode() << ", " << node->student.getName() << endl;

    preOrder(node->leftChild);
    preOrder(node->rightChild);
  }
};

void BST::inOrder(Node *node) {
  if (node != nullptr) {
    inOrder(node->leftChild);

    cout << node->student.getCode() << ", " << node->student.getName() << endl;

    inOrder(node->rightChild);
  }
};

void BST::postOrder(Node *node) {
  if (node != nullptr) {
    postOrder(node->leftChild);
    postOrder(node->rightChild);

    cout << node->student.getCode() << ", " << node->student.getName() << endl;
  }
};

// void BST::mirror(Node *node) {
//   if (node != nullptr) {
//     Node *tempNode = node->leftChild;

//     node->leftChild = node->rightChild;
//     node->rightChild = tempNode;

//     mirror(node->leftChild);
//     mirror(node->rightChild);
//   }
// }
