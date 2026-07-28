//Template is the foundation of the generic programming, which involves the writing of the code that is independent of any particular data
//Template is the formula or the blue print to create the generic class or function
#include<iostream>
/*int add(int x,int y)
{
    return x+y;

}
float add(float x,float y)
{
    return x+y;

}
double add(double x,double y)
{
    return x+y;
}*/
template<typename T,typename t>
t add(T x,t y){
    return x+y;
}
int main()
{
    std::cout<<"additiion of two integer three and four is:"<<add<int,double>(3,4.11);
    std::cout<<"additiion of two floating three and four is:"<<add<float>(3.44,4.444);
    std::cout<<"additiion of two double three and four is:"<<add<double>(3.45,4.44);
}

