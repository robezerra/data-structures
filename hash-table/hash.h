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
  void insert(Student student);
  void remove(Student student);
  void search(Student &student, bool &isFound);
  void print();
  bool isFull();
  bool isEmpty();
  int getCurrentSize();
};