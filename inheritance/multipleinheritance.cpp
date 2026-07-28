#include<iostream>
using namespace std;

class A{
public:
    void printmessage()
    {
        cout<<"class A print message function"<<endl;
    }
};

class B{
public:
    void printmessage()
    {
        cout<<"class B print message function"<<endl;
    }
};

class AB: public A, public B
{
};

int main()
{
    AB obj;
    obj.A::printmessage();  // Call A's function
    obj.B::printmessage();  // Call B's function
}