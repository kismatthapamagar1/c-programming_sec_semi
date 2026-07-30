#include<iostream>
class Student{
    protected:
    int rollno;
    public:
    Student(int r):rollno(r){
        std::cout<<"The roll no of the student is:"<<rollno<<std::endl;
    }
};
class Test:public Student
{
    protected:
    float m1;
    float m2;
    public:
    Test(int r,float m, float n):Student(r){
        m1=m;
        m2=n;
        std::cout<<"The marks in two subjects are"<<m1<<m2<<std::endl;

    }
    

};
class Result:public Test
{
    protected:
    float result;
    public:
    Result(int r,float m, float n):Test(r,m,n)
    {
        result=m1+m2;
        std::cout<<"The result is"<<result;
    }

};
int main()
{
    Result R(1,44.44,55.55);
    return 0;
}