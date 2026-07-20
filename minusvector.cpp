#include <iostream>
using namespace std;

class Vector {
private:
    int x, y, z;

public:
    // Constructor using initializer list
    Vector(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {}

    void display() {
        cout << "[" << x << " " << y << " " << z << "]" << endl;
    }

    // Unary minus operator
    Vector operator-() {
        return Vector(-x, -y, -z);
    }
};

int main() {
    Vector a(2, -5, 6);

    cout << "Original Vector: ";
    a.display();

    Vector b = -a;

    cout << "Negated Vector: ";
    b.display();

    return 0;
}