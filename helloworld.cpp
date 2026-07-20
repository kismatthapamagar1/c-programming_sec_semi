#include <iostream>
#include <cmath>
using namespace std;

// Namespace for Cube
namespace Cube {
    double side;

    void input() {
        cout << "Enter side of cube: ";
        cin >> side;
    }

    double volume() {
        return side * side * side;
    }

    double surfaceArea() {
        return 6 * side * side;
    }
}

// Namespace for Cylinder
namespace Cylinder {
    double radius, height;

    void input() {
        cout << "\nEnter radius and height of cylinder: ";
        cin >> radius >> height;
    }

    double volume() {
        return M_PI * radius * radius * height;
    }

    double surfaceArea() {
        return 2 * M_PI * radius * (radius + height);
    }
}

// Namespace for Pyramid (Square base)
namespace Pyramid {
    double base, height, slantHeight;

    void input() {
        cout << "\nEnter base length, height, and slant height of pyramid: ";
        cin >> base >> height >> slantHeight;
    }

    double volume() {
        return (1.0 / 3) * base * base * height;
    }

    double surfaceArea() {
        return base * base + 2 * base * slantHeight;
    }
}

int main() {
    // Cube
    Cube::input();
    cout << "Cube Volume: " << Cube::volume() << endl;
    cout << "Cube Surface Area: " << Cube::surfaceArea() << endl;

    // Cylinder
    Cylinder::input();
    cout << "Cylinder Volume: " << Cylinder::volume() << endl;
    cout << "Cylinder Surface Area: " << Cylinder::surfaceArea() << endl;

    // Pyramid
    Pyramid::input();
    cout << "Pyramid Volume: " << Pyramid::volume() << endl;
    cout << "Pyramid Surface Area: " << Pyramid::surfaceArea() << endl;

    return 0;
}