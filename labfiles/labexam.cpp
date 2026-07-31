/*#include <iostream>

template<typename T>
class Arraymax {
public:
    T maxvalue(T arr[], int size)
    {
        T max = arr[0];
        for(int i = 0; i < size; i++)
        {
            if(arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }
};

int main()
{
    int intArr[] = {10, 45, 23, 67, 12};
    float floatArr[] = {1.5f, 3.2f, 0.9f, 7.8f, 2.4f};

    Arraymax<int> obj1;
    Arraymax<float> obj2;

    std::cout << "Max integer: " << obj1.maxvalue(intArr, 5) << std::endl;
    std::cout << "Max float: " << obj2.maxvalue(floatArr, 5) << std::endl;

    return 0;
}*/
#include<iostream>
using namespace std;
template<typename T>
class Arraymax{
    public:
    T maxi(T arr[],int size)
    {
        T max= arr[0];
        for(int i=1;i<size;i++)
        {
            if(arr[i]>max)
            max=arr[i];

        }
        return max;
    }

};
int main()
{
    int intarr[]={10,20,30,40,50};
    float floatarr[]={1.2f,2.2f,3.3f,4.4f,5.5f};
    Arraymax <int> obj1;
    Arraymax <float> obj2;
    cout<<"the maximum value is:"<<obj1.maxi(intarr,5);
    cout<<"the maximum value is:"<<obj2.maxi(floatarr,5);
    return 0;
}
