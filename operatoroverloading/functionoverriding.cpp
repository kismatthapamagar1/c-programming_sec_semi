//if a derived class defines the same function as defined in the base class, it is known as function overriding
//if we create the object in the derived class and class the member function which exist in both classes(base and derived),the member function of the derived class is invoked and the function in the derived class is ignored
//It enables us to provide the specific implementation of the function which is already provided in the base class
#include<iostream>
using namespace std;
class Animal
{
    public:
    void makeSound(){
        cout<<"Animal sound";
        
    }
};
    class Dog:public Animal
    {
        public:
                void makeSound()
        {
            cout<<"Dog Barks";
        }
    };
    class Cat:public Animal
    {
        public:
        void makeSound()
        {
            cout<<"cat meow";
        }
    };
    int main()
    {
        Animal a1;
        a1.makeSound();
        Dog d1;
        d1.makeSound();
        Cat c1;
        c1.makeSound();
    }



