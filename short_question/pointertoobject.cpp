#include<iostream>
// pointer are the numbers that have both the  real and imaginary part
using namespace std;
class ComplexNumber{
    private:
    //data members
    int real;
    float imaginary;
    public:
    ComplexNumber()
    {


    }

    ComplexNumber(int r, float i)
    {
        real=r;
        imaginary=r;
    }
    void displaydata()
    {
        cout<<"real and imaginary parts are:"<<real<<"+"<<imaginary<<"i"<<endl;

    }
    int getrealpart()
        {
return real;
        }
        float getimaginarypart()
        {
            return imaginary;
        }
    
};
ComplexNumber add2numbers(ComplexNumber n1,ComplexNumber n2)
{
    int r;
    float i;
    r=n1.getrealpart()+n2.getrealpart();
    i=n1.getimaginarypart()+n2.getimaginarypart();
    ComplexNumber temp(r,i);
    return temp;
}
int main()
{
    ComplexNumber comp1(2,4),comp2(5,4),comp3;
   
    comp1.displaydata();
    comp2.displaydata();
    comp3=add2numbers(comp1,comp2);
    comp3.displaydata();
    ComplexNumber *ptr1;
    ptr1=&comp3;
    cout<<"Pointoid addvalueer to object";
    ptr1->displaydata();


    return 0;
}