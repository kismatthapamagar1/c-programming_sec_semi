#include<iostream>
using namespace std;
class Timezone
{
    protected:
    int hour;
    int minute;
    int second;
    public:
    Timezone():hour(0),minute(0),second(0)
    {
        cout<<"This is a default constructor"<<endl;
    }
    Timezone(int h, int m, int s):hour(h),minute(m),second(s){
        cout<<"The time format is:"<<hour<<":"<<minute<<":"<<second<<endl;
    }
    friend istream& operator>>(istream &in,Timezone t1);
    friend ostream& operator<<(ostream& out, Timezone t2);
    Timezone operator+(Timezone tt)
    {
        Timezone temp;
        temp.hour=hour+tt.hour;
        temp.minute=minute+tt.minute;
        temp.second= second+tt.second;
        return temp;


    }
    
};
istream& operator>>(istream &in,Timezone t1)
{
    cout<<"enter the time in the hour, minute and second format:"<<endl;
    in>>t1.hour>>t1.minute>>t1.second;
    return in;
}
ostream& operator<<(ostream &out,Timezone t2)
{
    
    out<<t2.hour<<t2.minute<<t2.second;
    return out;
}
int main()
{
    Timezone t1,t2,t3;
    cin>>t1;
    cin>>t2;
    t3=t1+t2;
    cout<<"time 1:"<<t1;
    cout<<"time 2:"<<t2;
    cout<<t3;
    
    return 0;
}