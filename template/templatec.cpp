#include<iostream>
using namespace std;

template <class T>
class Box {
    T value;
public:
    void setValue(T v);
    T getValue();
};

template <class T>
void Box<T>::setValue(T v) {
    value = v;
}

template <class T>
T Box<T>::getValue() {
    return value;
}

int main() {
    Box<int> b1;
    b1.setValue(10);
    cout << b1.getValue();

    return 0;
}