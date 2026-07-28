#include <iostream>
using namespace std;

class Vector {
private:
    int x, y, z;
    char type;   // 'R' for Row, 'C' for Column

public:
    // Constructor using initializer list
    Vector(int a = 0, int b = 0, int c = 0, char t = 'R')
        : x(a), y(b), z(c), type(t) {}

    // Display function
    void display() {
        if (type == 'R') {
            cout << "Row Vector: ";
            cout << "[" << x << " " << y << " " << z << "]" << endl;
        } else if (type == 'C') {
            cout << "Column Vector:" << endl;
            cout << "[" << x << "]" << endl;
            cout << "[" << y << "]" << endl;
            cout << "[" << z << "]" << endl;
        } else {
            cout << "Unknown vector type!" << endl;
        }
    }

    // Unary minus operator
    Vector operator-() {
        return Vector(-x, -y, -z, type); // keep same type
    }
};

int main() {
    // Row vector
    Vector a(2, -5, 6, 'R');

    // Column vector
    Vector c(2, -5, 6, 'C');

    cout << "Original Vectors:" << endl;
    a.display();
    c.display();

    Vector b = -a;
    Vector d = -c;

    cout << "\nAfter Negation:" << endl;
    b.display();
    d.display();

    return 0;
}