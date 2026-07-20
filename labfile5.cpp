#include <iostream>
using namespace std;

// Point class
class Point {
public:
    float x, y;

    Point(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }

    void display() {
        cout << "(" << x << ", " << y << ")";
    }
};

// Base class Polygon
class Polygon {
protected:
    int numberOfSides;
    Point centroid;

public:
    Polygon(int sides = 0, float x = 0, float y = 0) : centroid(x, y) {
        numberOfSides = sides;
    }

    void display() {
        cout << "Number of sides: " << numberOfSides << endl;
        cout << "Centroid: ";
        centroid.display();
        cout << endl;
    }

    void move(float dx, float dy) {
        centroid.x += dx;
        centroid.y += dy;
    }
};

// Derived class Triangle
class Triangle : public Polygon {
private:
    float base, height;

public:
    Triangle(float b, float h, float x, float y)
        : Polygon(3, x, y) {
        base = b;
        height = h;
    }

    float area() {
        return 0.5 * base * height;
    }

    void display() {
        Polygon::display();
        cout << "Triangle base: " << base << endl;
        cout << "Triangle height: " << height << endl;
        cout << "Area: " << area() << endl;
    }
};

// Derived class Rectangle
class Rectangle : public Polygon {
private:
    float length, width;

public:
    Rectangle(float l, float w, float x, float y)
        : Polygon(4, x, y) {
        length = l;
        width = w;
    }

    float area() {
        return length * width;
    }

    void display() {
        Polygon::display();
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << area() << endl;
    }
};

// Main function
int main() {
    Triangle t(10, 5, 2, 3);
    Rectangle r(4, 6, 1, 1);

    cout << "Triangle Details:\n";
    t.display();

    cout << "\nMoving Triangle by (2,2)...\n";
    t.move(2, 2);
    t.display();

    cout << "\nRectangle Details:\n";
    r.display();

    cout << "\nMoving Rectangle by (3,3)...\n";
    r.move(3, 3);
    r.display();

    return 0;
}