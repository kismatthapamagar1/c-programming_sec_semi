#include <iostream>
#include <queue>

class Queue {
private:
    std::queue<int> value;   // STL queue object

public:

    // Insert element-getter
    void insert(int data) {
        value.push(data);
    }

    // Remove first inserted element
    void remove() {
        if (value.empty()) {
            std::cout << "Queue is empty\n";
            return;
        }

        std::cout << "Removed element: "
                  << value.front() << std::endl;

        value.pop();
    }

    // Display first element
    void front() {
        if (value.empty()) {
            std::cout << "Queue is empty\n";
            return;
        }

        std::cout << "Front element: "
                  << value.front() << std::endl;
    }

    // Display last element
    void rear() {
        if (value.empty()) {
            std::cout << "Queue is empty\n";
            return;
        }

        std::cout << "Rear element: "
                  << value.back() << std::endl;
    }
};


int main() {

    Queue q;

    q.insert(10);
    q.insert(20);
    q.insert(30);

    q.front();   // First inserted element
    q.rear();    // Last inserted element

    q.remove();

    q.front();

    return 0;
}