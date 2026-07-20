/*#include<iostream>
using namespace std;
class MyBase{
    public:
    void show()
    {
        cout<<"Base class show function is called";

    }
    virtual void print()
    {
        cout<<"Base class print function is called";

    }

};
class MyDerived:public MyBase{
    void show()
    {
        cout<<"Derived class show function is called";

    }
     void print()
    {
        cout<<"Derived class print function is called";

    }


};
int main()
{
    MyBase *baseptr;
    MyDerived derivedobj;
    baseptr=&derivedobj;
    //runtime polymorphism
        baseptr->print();//derived class print function was called
    baseptr->show(); // base class show function was called 

}*/
/*#include<iostream>
using namespace std;
class Animal{
    public:
   virtual void eat()
    {
        cout<<"I'm eating generic food";

    }

};
class Cat:public Animal
{
    public:
    void eat()
    {
        cout<<"I 'm eating a rat";

    }

};
class Dog:public Animal
{
    public:
    void eat()
    {
        cout<<"I 'm eating a dog food";

    }
};
void function1(Animal *xyz)
{
    xyz->eat();
}
int main()
{
    Animal *ptr;
    Dog obj1;
    Cat obj2;
    ptr=&obj2;
  function1(ptr);

}*/
#include<iostream>
using namespace std;
class Shape{
    public:
    virtual void getarea()=0;//pure virtaul function

};
class Circle: public Shape{
    public:
    void getarea()
    {
        cout<<"enter the radius of the circle";
        int r;

        cin>>r;
        cout<<"the area of the circle:"<<(3.14*r*r);
    }

};
int main()
{
   //Shape obj;
   Circle c1;
   c1.getarea();
}