#include<iostream>
using namespace std;
template<typename T>
class Weight
{
    private:
    T kgs;
    public:
    void setdata(T x)
    {
        kgs=x;
    }
    T getdata(){
        return kgs;
    }
};
int main(){
    Weight <int>obj1;
    obj1.setdata(5);
    cout<<"the required value is "<<obj1.getdata();

Weight <double>obj2;
obj2.setdata(4.555);
cout<<"the required value is "<<obj2.getdata();


}