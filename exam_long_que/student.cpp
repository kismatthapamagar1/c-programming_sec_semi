#include<iostream>
#include<string>

class Student
{
    private: 
    std::string name;
    long issuebookid[10];
    int count;
    public:
    Student()
    {
        count =0;
    }
    void getname(std::string n)
    {
        name=n;

    }
    void displayname()
    {
        std::cout<<"Name="<<name<<std::endl;
    }
    void issuebooks(long bookid)
    {
        if(count<10)
        {
            issuebookid[count]=bookid;
            count++;
        }
    }
   void displayissuedbooks()
   {
    for(int i=0;i<count;i++)
    {
        std::cout<<"issued book="<<issuebookid[i];

    }
   }



};
int main()
{
    Student s;
    s.getname("kismat");
    s.displayname();
    s.issuebooks(111);
    s.issuebooks(222);
    s.issuebooks(333);
    s.displayissuedbooks();
    return 0;



}