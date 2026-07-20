/*#include <iostream>
#include <stdexcept>
using namespace std;

// Generic Interface
template <class T>
class IQueue {
public:
    virtual void insert(T) = 0;
    virtual void remove() = 0;
    virtual T front() = 0;
    virtual T rear() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};

// Generic ArrayQueue
template <class T>
class ArrayQueue : public IQueue<T> {
private:
    T *arr;
    int capacity;
    int frontIndex, rearIndex, count;

public:
    ArrayQueue(int size) {
        capacity = size;
        arr = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    void insert(T x) {
        if (isFull()) {
            throw runtime_error("Queue is full");
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = x;
        count++;
    }

    void remove() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    T front() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return arr[frontIndex];
    }

    T rear() {
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

    ~ArrayQueue() {
        delete[] arr;
    }
};

// Main function (testing)
int main() {
    ArrayQueue<int> q1(3);
    q1.insert(10);
    q1.insert(20);
    cout << "Front (int): " << q1.front() << endl;

    ArrayQueue<string> q2(2);
    q2.insert("Hello");
    q2.insert("World");
    cout << "Rear (string): " << q2.rear() << endl;

    return 0;
}*/
#include <iostream>
using namespace std;

// Function template for Bubble Sort
template <class T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display array
template <class T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int arr1[] = {5, 2, 9, 1, 3};
    int n1 = 5;

    cout << "Before sorting (int): ";
    display(arr1, n1);

    bubbleSort(arr1, n1);

    cout << "After sorting (int): ";
    display(arr1, n1);

    // Using with float
    float arr2[] = {3.2, 1.5, 4.8, 2.1};
    int n2 = 4;

    cout << "\nBefore sorting (float): ";
    display(arr2, n2);

    bubbleSort(arr2, n2);

    cout << "After sorting (float): ";
    display(arr2, n2);

    return 0;
}