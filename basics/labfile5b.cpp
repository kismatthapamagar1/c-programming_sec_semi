#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int a = 0, int b = 0) {
        x = a;
        y = b;
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void display() {
        std::cout << "(" << x << ", " << y << ")";
    }
};


// Base class
class Polygon {

protected:
    int numberOfSides;
    Point centroid;

public:

    Polygon(int sides, int x, int y)
        : numberOfSides(sides), centroid(x, y) {
    }


    void display() {

        std::cout << "Number of sides: "
                  << numberOfSides << std::endl;

        std::cout << "Centroid: ";
        centroid.display();

        std::cout << std::endl;
    }


    void move(int dx, int dy) {

        centroid.move(dx, dy);
    }
};


// Derived class Triangle
class Triangle : public Polygon {

private:
    float base;
    float height;

public:

    Triangle(float b, float h, int x, int y)
        : Polygon(3, x, y) {
        
        base = b;
        height = h;
    }


    void area() {

        std::cout << "Triangle Area: "
                  << 0.5 * base * height
                  << std::endl;
    }


    void display() {

        Polygon::display();

        std::cout << "Base: "
                  << base << std::endl;

        std::cout << "Height: "
                  << height << std::endl;
    }
};


// Derived class Rectangle
class Rectangle : public Polygon {

private:
    float length;
    float width;

public:

    Rectangle(float l, float w, int x, int y)
        : Polygon(4, x, y) {

        length = l;
        width = w;
    }


    void area() {

        std::cout << "Rectangle Area: "
                  << length * width
                  << std::endl;
    }


    void display() {

        Polygon::display();

        std::cout << "Length: "
                  << length << std::endl;

        std::cout << "Width: "
                  << width << std::endl;
    }
};



int main() {

    Triangle t(5, 10, 2, 3);

    std::cout << "Triangle Details:\n";
    t.display();
    t.area();

    t.move(5, 5);

    std::cout << "\nAfter moving Triangle:\n";
    t.display();


    Rectangle r(8, 4, 10, 20);

    std::cout << "\nRectangle Details:\n";
    r.display();
    r.area();


    return 0;
}