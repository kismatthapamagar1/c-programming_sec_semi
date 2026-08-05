#include<iostream>
using namespace std;




int main()
{
    int chaiTemperature[5]={50,11,90,89};
    cout<<"Chai temperatures:";
    for(int i=0;i<5;i++)// garbage value ni dinxa if given i>=5
    {
        cout<<chaiTemperature[i]<<"degree celsius"<<endl;


    }
    return 0;
}