#include<iostream>

class Point
{
    private:
    double x,y;
    public: 

    Point()
    {
        x=y=0;
    }
    Point(double a, double b)
    {
        x=a;
        y=b;

    }
    double getx()
    {
        return x;

    }
    double gety()
    {
        return y;
    }


};
class Rectangle
{
    private:
    Point p1,p2;
    public:
    void setpoints(const Point &c,const Point &d)
    {
        p1=c;
        p2=d;

    }
    void getdimensions(double &width, double &height)
    {
        width=p2.getx()-p1.getx();
        height=p2.gety()-p1.gety();


    }
    double perimeter()
    {
        double width,height;
        getdimensions(width,height);
        double p=2*(width+height );
        return p;

    }

};
int main()
{
    Point A(2,3);
    Point B(3,3);
    Rectangle r;
    r.setpoints(A,B);
    double w,h;
    r.getdimensions(w,h);
    std::cout<<"width="<<w;
    std::cout<<"height="<<h;
    std::cout<<"perimeter="<<r.perimeter();
    

}