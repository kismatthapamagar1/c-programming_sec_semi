#include <iostream>// polygon has a relation with the point not is a relationship

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
        x = x + dx;
        y = y + dy;
    }

    void display() {
        std::cout << "Centroid coordinates: ("
                  << x << ", " << y << ")" << std::endl;
    }
};


class Polygon {

private:
    int numberOfSides;
    Point centroid; // data type is point yrrr

public:

    // Constructor
    Polygon(int sides, int x, int y) 
        : numberOfSides(sides), centroid(x, y) {
    }


    // Display polygon details
    void display() {

        std::cout << "Number of sides: "
                  << numberOfSides << std::endl;

        centroid.display();
    }


    // Move polygon to new location
    void move(int dx, int dy) {

        centroid.move(dx, dy); //getters
    }
};


int main() {

    Polygon p(5, 10, 20);

    std::cout << "Before moving:\n";
    p.display();


    p.move(5, 10);

    std::cout << "\nAfter moving:\n";
    p.display();


    return 0;
}