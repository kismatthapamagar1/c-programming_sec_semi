#include <iostream>
using namespace std;

class Counter {
private:
    static int count;  // static data member

public:
    // Constructor increments count as the static member are used to track down the number of the object called,like a counter
    Counter() {
        count++;
    }

    // Static member function to display count
    static void displayCount() {
        cout << "Total objects created: " << count << endl;
    }
};

// Definition of static data member,always outside class definition
int Counter:: count = 0;

int main() {
    Counter c1, c2, c3;  // creating objects

    // Calling static member function
    Counter::displayCount();// static member are class basis no need of the object to call

    return 0;
}