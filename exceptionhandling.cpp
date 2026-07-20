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
        throw(b);
    }
    catch(int n)
    {
        cout<<"the entered value is "<<n;


    }
    return 0;
}


