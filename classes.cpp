// c++ program to find the vector sum of in 3 dimensions
#include<iostream>


class Vector{

    private:
    double x,y,z;
    public:
    Vector()
    {
        x=y=z=0;
    }
    Vector(double a, double b, double c)
    {
        x=a;
        y=b; 
        z=c;
    }
    Vector add(Vector v)
    {
        x=x+v.x;
        y=y+v.y;
        z=z+v.z;
        Vector temp(x,y,z);
        return temp;

    }
    void display()
    {
        std::cout<<"["<<x<<" "<<y<<" "<<z<<"]"<<std::endl;

    }

};
int main()
{
    Vector v1(1,2,3);
    Vector v2(1,2,3);
    Vector v3= v1.add(v2);
    v3.display();
    
}