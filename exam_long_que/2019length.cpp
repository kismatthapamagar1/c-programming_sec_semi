#include<iostream>
class Length
{
    private:
    double inch;
    double feet;
    public:
    Length():inch(0),feet(0){}
    Length(double fe,double len):feet(fe),inch(len){

    }
    void display()
    {
        std::cout<<"The first value of the inch snd feet are:"<<inch<<","<<feet<<std::endl;

    }
    Length operator+( Length l)
    {
        Length temp;
        temp.feet=this->feet+l.feet;
        temp.inch=this->inch+l.inch;
        
        
        if(temp.inch>=12)
        {
            temp.feet+=(int)(temp.inch / 12);
            temp.inch = temp.inch - ((int)(temp.inch / 12) * 12);
        }
        return temp;

    }


};
int main()
{
    Length l1(2,9);
    Length l2(3,9);
    Length l3;
    l3=l1+l2;
  l3.display();
}