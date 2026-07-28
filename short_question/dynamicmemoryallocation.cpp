#include <iostream>

class ArrayDemo {
    int *arr;
    int size;

public:
    // Constructor: allocate memory
    ArrayDemo(int s) {
        size = s;
        arr = new int[size];
        std::cout << "Memory allocated\n";
    }

    // Input function
    void input() {
        std::cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; i++) {
            std::cin >> arr[i];
        }
    }

    // Display function
    void display() {
        std::cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Destructor: deallocate memory
    ~ArrayDemo() {
        delete[] arr;
        std::cout << "Memory deallocated\n";
    }
};

int main() {
    ArrayDemo obj(5);

    obj.input();
    obj.display();

    return 0;
}