#include <iostream>

// Base class
class Person {
protected:
    std::string name;
    int age;

public:
    void getPersonData() {//setter
        std::cout << "Enter name and age: ";
        std::cin >> name >> age;
    }

    void displayPersonData() { //getter
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }
};

// Student class (virtual inheritance)
class Student : virtual public Person {
protected:
    int rollNo;

public:
    void getStudentData() {
        std::cout << "Enter roll number: ";
        std::cin >> rollNo;
    }

    void displayStudentData() {
        std::cout << "Roll No: " << rollNo << std::endl;
    }
};

// Teacher class (virtual inheritance)
class Teacher : virtual public Person {
protected:
    std::string subject;

public:
    void getTeacherData() {
        std::cout << "Enter subject: ";
        std::cin >> subject;
    }

    void displayTeacherData() {
        std::cout << "Subject: " << subject << std::endl;
    }
};

// Derived class combining both
class TeachingAssistant : public Student, public Teacher {
public:
    void getData() {
        getPersonData();     // Only one Person object exists
        getStudentData();
        getTeacherData();
    }

    void displayData() {
        displayPersonData();
        displayStudentData();
        displayTeacherData();
    }
};

int main() {
    TeachingAssistant ta;

    ta.getData();
    std::cout << "\n--- Details ---\n";
    ta.displayData();

    return 0;
}