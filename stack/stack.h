typedef int TypeStackItem;

const int MAX_ITEMS = 5;

class Stack {
private:
  int stackLength;
  TypeStackItem *stackStructure = nullptr;

public:
  Stack();
  ~Stack();

  void insert(TypeStackItem item);
  void print();
  TypeStackItem remove();
  bool isFull();
  bool isEmpty();
  int lenght();
};