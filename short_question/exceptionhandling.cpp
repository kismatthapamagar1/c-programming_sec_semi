#include <iostream>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int index;

    std::cout << "Array elements are: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\nEnter index: ";
    std::cin >> index;

    try {
        // Manual bounds checking
        if (index < 0 || index >= 5) {
            throw index;
        }

        std::cout << "Element at index " << index 
                  << " = " << arr[index] << std::endl;
    }
    catch (int i) {
        std::cout << "Exception: Index " << i 
                  << " is out of bounds!" << std::endl;
    }

    return 0;
}