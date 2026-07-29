#include <iostream>
#include <queue>
#include <stdexcept>

// Interface class
class IQueue {
public:
    virtual void insert(int data) = 0;
    virtual void remove() = 0;
    virtual int front() = 0;
    virtual int rear() = 0;
};


// Queue class
class ArrayQueue : public IQueue {

private:
    std::queue<int> value;   // STL queue object

public:

    // Insert element
    void insert(int data) override {
        value.push(data);
    }


    // Remove first inserted element
    void remove() override {

        if (value.empty()) {
            throw std::runtime_error("Queue is empty");
        }

        std::cout << "Removed: "
                  << value.front() << std::endl;

        value.pop();
    }


    // Return first element
    int front() override {

        if (value.empty()) {
            throw "Queue is empty";
        }

        return value.front();
    }


    // Return last element
    int rear() override {

        if (value.empty()) {
            throw "Queue is empty";
        }

        return value.back();
    }
};


int main() {

    try {

        ArrayQueue q;

        q.insert(10);
        q.insert(20);
        q.insert(30);

        std::cout << "Front element: "
                  << q.front() << std::endl;

        std::cout << "Rear element: "
                  << q.rear() << std::endl;

        q.remove();

        std::cout << "New front element: "
                  << q.front() << std::endl;

    }

    catch(const char* msg) {

        std::cout << "Exception: "
                  << msg<< std::endl;
    }

    return 0;
}