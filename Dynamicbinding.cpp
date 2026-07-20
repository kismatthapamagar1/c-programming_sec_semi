#include<iostream>
using namespace std;
// base class
class Devices{
    public:
    // runtime polymorphism is dynamically don e during the run time;
    virtual void show()
    {
        cout<<"connecting the generic devices";

    }


};
class wifiDevices: public Devices
{
    public:
    void show()
    {
        cout<<"connecting the wifidevices";

    }



};

class bluetoothDevices: public Devices
{
    public:
    void show()
    {
        cout<<"connecting the wifidevices"<<endl;
        
    }



};
    int main()
    {
        Devices *ptr;
    wifiDevices w1;
    bluetoothDevices b1;
    ptr=&w1;
    ptr->show();
    ptr=&b1;
    
     ptr->show();




    }