#ifndef QUEUETP_H_
#define QUEUETP_H_

template <typename Item>
class Queue {
private:
    enum { Q_SIZE = 10 };
    class Node {
    public:
        Item item;
        Node* next;
        Node(const Item& i) : item(i), next(nullptr) {}
    };
    Node* front;
    Node* rear;
    int items;
    const int qsize;
    Queue(const Queue&) = delete;             // disable copy constructor
    Queue& operator=(const Queue&) = delete;  // disable assignment operator

public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isEmpty() const { return items == 0; }
    bool isFull() const { return items == qsize; }
    int queueSize() const { return items; }
    bool enqueue(const Item& item);
    bool dequeue(Item& item);
};

template <typename Item>
Queue<Item>::Queue(int qs)
    : front(nullptr), rear(nullptr), items(0), qsize(qs) {}

template <typename Item>
Queue<Item>::~Queue() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename Item>
bool Queue<Item>::enqueue(const Item& item) {
    if (isFull()) {
        return false;
    }
    Node* newNode = new Node(item);
    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    items++;
    return true;
}

template <typename Item>
bool Queue<Item>::dequeue(Item& item) {
    if (isEmpty()) {
        return false;
    }
    item = front->item;
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    items--;
    return true;
}

#endif  // QUEUETP_H_