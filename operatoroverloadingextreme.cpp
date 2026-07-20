#include <iostream>
using namespace std;

class Vector {
private:
    int x, y, z;
    char type;   // 'R' or 'C'

public:
    // Constructor
    Vector(int a = 0, int b = 0, int c = 0, char t = 'R')
        : x(a), y(b), z(c), type(t) {}

    // ➤ operator + (same type only)
    Vector operator+(const Vector& v) {
        if (type != v.type) {
            cout << "Addition not allowed for different types!\n";
            return *this;
        }
        return Vector(x + v.x, y + v.y, z + v.z, type);
    }

    // ➤ operator -
    Vector operator-(const Vector& v) {
        if (type != v.type) {
            cout << "Subtraction not allowed for different types!\n";
            return *this;
        }
        return Vector(x - v.x, y - v.y, z - v.z, type);
    }

    // ➤ operator +=
    Vector operator+=(const Vector& v) {
        if (type != v.type) {
            cout << "Addition not allowed!\n";
            return *this;
        }
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    // ➤ operator ==
    bool operator==(const Vector& v) {
        return (x == v.x && y == v.y && z == v.z && type == v.type);
    }

    // ➤ operator >
    bool operator>(const Vector& v) {
        if (type != v.type) {
            cout << "Comparison not allowed!\n";
            return false;
        }
        return (x > v.x && y > v.y && z > v.z);
    }

    // ➤ operator << (output)
    friend ostream& operator<<(ostream& out, const Vector& v) {
        if (v.type == 'R') {
            out << "[" << v.x << " " << v.y << " " << v.z << "]";
        } else {
            out << "[" << v.x << "]\n"
                << "[" << v.y << "]\n"
                << "[" << v.z << "]";
        }
        return out;
    }

    // ➤ operator >> (input)
    friend istream& operator>>(istream& in, Vector& v) {
        cout << "Enter x y z: ";
        in >> v.x >> v.y >> v.z;
        cout << "Enter type (R/C): ";
        in >> v.type;
        return in;
    }
};

int main() {
    Vector a, b;

    cout << "Enter Vector A:\n";
    cin >> a;

    cout << "Enter Vector B:\n";
    cin >> b;

    cout << "\nA = \n" << a << endl;
    cout << "B = \n" << b << endl;

    // Addition
    Vector c = a + b;
    cout << "\nA + B = \n" << c << endl;

    // Subtraction
    Vector d = a - b;
    cout << "\nA - B = \n" << d << endl;

    // +=
    a += b;
    cout << "\nAfter A += B, A = \n" << a << endl;

    // ==
    if (a == b)
        cout << "\nA and B are equal\n";
    else
        cout << "\nA and B are not equal\n";

    // >
    if (a > b)
        cout << "\nA is greater than B\n";
    else
        cout << "\nA is NOT greater than B\n";

    return 0;
}