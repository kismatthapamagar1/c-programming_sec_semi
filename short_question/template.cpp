/*The basic difference between the function template and the function template is that the function template just
sets and get the value where as in the class template we instiate the member data like T name;*/
#include <iostream>

// Function template with reference parameters
template <class T>
T greatest(T &a, T &b, T &c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

int main() {
    int x = 10, y = 25, z = 15;

    std::cout << "Greatest number is: " 
              << greatest(x, y, z) << std::endl;

    return 0;
}