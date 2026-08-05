#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"<Enter two numbers:"<<endl;
    cin>>a>>b;
    try
    {
        if(b!=0)
        {
            c=a/b;
            cout<<"The required answer is "<<c;
        }
        else
        throw"error aayo";
    }
    catch(const char *msg)
    {
        cerr<<"the entered value is "<<msg;


    }
    return 0;
}


