#include <iostream>
#include <stdexcept>
using namespace std;

// Interface class
class IQueue {
public:
    virtual void insert(int) = 0;
    virtual void remove() = 0;
    virtual int front() = 0;
    virtual int rear() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};

// Array-based Queue
class ArrayQueue : public IQueue {
private:
    int *arr;
    int capacity;
    int frontIndex, rearIndex, count;

public:
    ArrayQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    // Insert element
    void insert(int x) {
        if (isFull()) {
            throw runtime_error("Queue is full");
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = x;
        count++;
    }

    // Remove element
    void remove() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    // Peek front
    int front() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return arr[frontIndex];
    }

    // Peek rear
    int rear() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return arr[rearIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    // Destructor
    ~ArrayQueue() {
        delete[] arr;
    }
};

// Main (for testing)
int main() {
    ArrayQueue q(3);

    try {
        q.insert(10);
        q.insert(20);
        q.insert(30);

        cout << "Front: " << q.front() << endl;
        cout << "Rear: " << q.rear() << endl;

        q.remove();
        cout << "After removal, Front: " << q.front() << endl;

        q.insert(40); // circular behavior
        cout << "Rear after insert: " << q.rear() << endl;

        // q.insert(50); // will throw exception (full)

    } catch (exception &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}