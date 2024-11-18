#include "student.h"

class Hash {
private:
  int hashFunction(Student student);
  int MAX_ITEMS;
  int MAX_SIZE;
  int itemsQuantity;
  Student *structure;

public:
  Hash(int vectorSize, int maxSize);
  ~Hash();
  void push(Student student);
  void pop(Student student);
  void search(Student &student, bool &isFound);
  void print();
  bool isFull();
  bool isEmpty();
  int getCurrentSize();
};