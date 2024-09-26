typedef int StackItemType;

const int MAX_ITEMS = 5;

class Stack {
private:
  int stackLength;
  StackItemType *stackStructure = nullptr;

public:
  Stack();
  ~Stack();

  void insert(StackItemType item);
  void print();
  StackItemType remove();
  bool isFull();
  bool isEmpty();
  int lenght();
};