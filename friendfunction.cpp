//friend function
/* A friend function is a special type of the non member function that is defined outside the class but it has the right to access the private and protected member of that class */
/*Even though the prototype of the friend function appears in the class definition , friends are not the member functions*/
#include<iostream>
using namespace std;
class Distance{
    private:
    int meters;
    public:
    Distance()
    {
        meters=0;
    }
    void displaydata()
    {
        cout<<"Meter value:"<<meters;
    }
    // signature of the friend function
    friend void addvalue(Distance &d);


};
void addvalue(Distance &d)
{
    d.meters=d.meters+5;
}
int main()
{
    Distance d1;
    d1.displaydata();
    addvalue(d1);
    d1.displaydata();

}

