#include <iostream>

// Function using reference variables
void swapNumbers(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;

    std::cout << "Before swapping: x = " << x << ", y = " << y << std::endl;

    swapNumbers(x, y);  // Call by reference

    std::cout << "After swapping: x = " << x << ", y = " << y << std::endl;

    return 0;
}