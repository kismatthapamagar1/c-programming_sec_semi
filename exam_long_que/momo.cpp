#include<iostream>
class Momo{
    public:
    virtual int get_price()=0;
    virtual void display_price()=0;

};
class vegmomo:public Momo{
    int get_price()
    {
        return 150;

    }
    void display_price()
    {
        std::cout<<"The price of the veg momo is"<<get_price()<<std::endl;
    }
};
class buffmomo: public Momo{
    int get_price()
    {
        return 150;

    }
    void display_price()
    {
        std::cout<<"The price of the buff momo is"<<get_price()<<std::endl;
    }
};
class chickenmomo:public Momo{
    int get_price()
    {
        return 200;

    }
    void display_price()
    {
        std::cout<<"The price of the chicken momo is"<<get_price()<<std::endl;
    }
};
int main()
{
    Momo *ptr;
    vegmomo v1;
    buffmomo b1;
    chickenmomo c1;
  
    ptr = &v1;
    ptr->display_price();
    ptr = &b1;
    ptr->display_price();
    ptr = &c1;
    ptr->display_price();
    return 0;

}