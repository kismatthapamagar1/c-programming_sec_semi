// #include <iostream>

// // Base class
// class Person {
// protected:
//     std::string name;
//     int age;

// public:
//     void getPersonData() {//setter
//         std::cout << "Enter name and age: ";
//         std::cin >> name >> age;
//     }

//     void displayPersonData() { //getter
//         std::cout << "Name: " << name << std::endl;
//         std::cout << "Age: " << age << std::endl;
//     }
// };

// // Student class (virtual inheritance)
// class Student : virtual public Person {
// protected:
//     int rollNo;

// public:
//     void getStudentData() {
//         std::cout << "Enter roll number: ";
//         std::cin >> rollNo;
//     }

//     void displayStudentData() {
//         std::cout << "Roll No: " << rollNo << std::endl;
//     }
// };

// // Teacher class (virtual inheritance)
// class Teacher : virtual public Person {
// protected:
//     std::string subject;

// public:
//     void getTeacherData() {
//         std::cout << "Enter subject: ";
//         std::cin >> subject;
//     }

//     void displayTeacherData() {
//         std::cout << "Subject: " << subject << std::endl;
//     }
// };

// // Derived class combining both
// class TeachingAssistant : public Student, public Teacher {
// public:
//     void getData() {
//         getPersonData();     // Only one Person object exists
//         getStudentData();
//         getTeacherData();
//     }

//     void displayData() {
//         displayPersonData();
//         displayStudentData();
//         displayTeacherData();
//     }
// };

// int main() {
//     TeachingAssistant ta;

//     ta.getData();
//     std::cout << "\n--- Details ---\n";
//     ta.displayData();

//     return 0;
// }
#include <iostream>
#include <string>

// Base class
class Person {
protected:
    std::string name;
    int age;

public:
    // Parameterized constructor
    Person(std::string n, int a) {
        name = n;
        age = a;
    }

    void displayPersonData() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }
};

// Student class (virtual inheritance)
class Student : virtual public Person {
protected:
    int rollNo;

public:
    Student(int r) : Person("", 0) {   // required but ignored
        rollNo = r;
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
    Teacher(std::string sub) : Person("",0) {   // required but ignored
        subject = sub;
    }

    void displayTeacherData() {
        std::cout << "Subject: " << subject << std::endl;
    }
};

// Derived class
class TeachingAssistant : public Student, public Teacher {
public:
    TeachingAssistant(std::string n, int a, int r, std::string sub)
        : Person(n, a), Student(r), Teacher(sub) {}

    void displayData() {
        displayPersonData();
        displayStudentData();
        displayTeacherData();
    }
};

int main() {
    // Direct values passed
    TeachingAssistant ta("Ram", 20, 101, "Math");

    std::cout << "\n--- Details ---\n";
    ta.displayData();

    return 0;
}