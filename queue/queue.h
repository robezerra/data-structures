typedef int QueueItemType;

const int MAX_ITEMS = 3;

class Queue {
private:
  int front, back;

  QueueItemType *structure;

public:
  Queue();
  ~Queue();

  bool isEmpty();
  bool isFull();

  void enqueue(QueueItemType item);
  void dequeue();

  void peek();
  void rear();

  void print();
};