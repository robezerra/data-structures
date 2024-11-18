typedef int DynamicStackItemType;

const int MAX_ITEMS = 5;

struct Node {
  DynamicStackItemType content;
  Node *next;
};

class DynamicStack {
private:
  Node *topNode;

public:
  DynamicStack();
  ~DynamicStack();

  void push(DynamicStackItemType item);
  DynamicStackItemType pop();
  bool isFull();
  bool isEmpty();
  void print();
};