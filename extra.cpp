#include <iostream>
#include <fstream>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a) {
        name = n;
        age = a;
        cout << "Person Constructor Called\n";
    }

    // Virtual function
    virtual void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Destructor
    ~Person() {
        cout << "Person Destructor Called\n";
    }
};

// Derived class
class Student : public Person {
private:
    int marks;

public:
    // Constructor using base class constructor
    Student(string n, int a, int m) : Person(n, a) {
        marks = m;
        cout << "Student Constructor Called\n";
    }

    // Function overriding
    void display() override {
        cout << "Name: " << name << ", Age: " << age 
             << ", Marks: " << marks << endl;
    }

    // Destructor
    ~Student() {
        cout << "Student Destructor Called\n";
    }
};

int main() {
    // Creating object
    Student s("Ali", 20, 85);

    // Polymorphism (base pointer)
    Person* p;
    p = &s;
    p->display();

    // File handling
    ofstream file("student.txt");
    file << "Student Data:\n";
    file << "Ali 20 85";
    file.close();

    cout << "Data written to file\n";

    return 0;
}
