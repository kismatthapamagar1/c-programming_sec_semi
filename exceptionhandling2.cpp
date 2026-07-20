
#include<iostream>
using namespace std;
class MyPrinter
{
    string name;
    int availablepaper;
    public:
    MyPrinter(string name,int availablepaper)
    {
        this->name=name;
        this->availablepaper=availablepaper;

    }
    void print(string doctext)
{
    int requiredpaper=doctext.length()/10;
    if(requiredpaper>availablepaper)
    {
        throw"there is an exception";
    }
    cout<<"printing....."<<doctext;
    availablepaper-=requiredpaper;

}
};
int main()
{
    MyPrinter p("Kismat Thapa Magar",100);
    try{

    p.print("Kismat Thapa Magar is an engineering student at Kathmandu university loacated at Dhulikhel Kavrepalanchowk.");
    }
    catch(const char* n )
    {
        cout<<"exception happened"<<n;

    }
    catch(...)
    {
        cout<<"Default file handling";
    }
    return 0;


}