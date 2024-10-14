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

  void insert(DynamicStackItemType item);
  DynamicStackItemType remove();
  bool isFull();
  bool isEmpty();
  void print();
};