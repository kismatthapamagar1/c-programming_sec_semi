#include<iostream>

template <class T>
class Arraystats{
private:
    T arr[10];
    int size;

public:
    void input()
    {
        std::cout<<"Enter the size of the array:"<<std::endl;
        std::cin>>size;

        if(size > 10) {
            std::cout<<"Size exceeds limit!"<<std::endl;
            return;
        }

        std::cout<<"Enter the array of numbers"<<std::endl;
        
        for(int i=0;i<size;i++)
        {
            std::cin>>arr[i];
        }
    }

    T printlargest()
    {
        T max=arr[0];
        for(int i=1;i<size;i++)
        {
            if(arr[i]>max)
                max=arr[i];
        }
        return max;
    }

    double average()
    {
        T sum = T();

        for(int i=0;i<size;i++)
        {
            sum += arr[i];
        }
        return (double)sum/size;
    }

    void display()
    {
        std::cout<<"The largest number in the array is: "<<printlargest()<<std::endl;
        std::cout<<"The average value of the given numbers is: "<<average()<<std::endl;
    }
};

int main()
{
    Arraystats<int> obj1;
    obj1.input();
    obj1.display();
    return 0;
}