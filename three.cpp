#include<iostream>
using namespace std;
int totalChaiServed(int chai[],int size)
{
    int total=0;
    for(int i=0;i<size;i++)
    {
        total+=chai[i];
    }
    return total;


}


int main()
{
    int chaiServed[7]={40,44,66,77,88,99,44};
    int total=totalChaiServed(chaiServed,7);


    return 0;
}