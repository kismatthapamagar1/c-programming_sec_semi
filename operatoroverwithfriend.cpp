#include<iostream>
class Height{
    private:
    int meters;
    int cm;
    public:
    Height()
    {
        meters=0;
        cm=0;
    }
    Height(int m,int c): meters(m),cm(c){
        if(cm>100)
        {
            m+=cm/100;
            cm=cm%100;

        }
    }
    friend Height operator-(Height h1,Height h2);
    void display()
    {
        std::cout<<"the height is"<<meters<<"meters and "<<cm<<"cm"<<std::endl;
    }

};
Height operator-(Height h1, Height h2){
    Height temp;
    temp.meters=h1.meters+h2.meters;
    temp.cm=h1.cm+h.cm



}
