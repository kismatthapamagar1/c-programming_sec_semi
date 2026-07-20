#include <iostream>
using namespace std;

int main() {
    int a, b, temp;

    // Input two numbers
    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    // Swapping logic
    temp = a;
    a = b;
    b = temp;

    // Output swapped numbers
    cout << "After swapping:" << endl;
    cout << "First number = " << a << endl;
    cout << "Second number = " << b << endl;

    return 0;
}