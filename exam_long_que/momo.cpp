#include<iostream>
class Momo{
    public:
    virtual int get_price()=0;
    virtual void display_price()=0;

};
class vegmomo{
    int getprice()
    {
        return 150;

    }
    void display_price()
    {
        std::cout<<"The price of the veg momo is"<<getprice()<<std::endl;
    }
};
class buffmomo{
    int getprice()
    {
        return 150;

    }
    void display_price()
    {
        std::cout<<"The price of the buff momo is"<<getprice()<<std::endl;
    }
};
class chickenmomo{
    int getprice()
    {
        return 200;

    }
    void display_price()
    {
        std::cout<<"The price of the chicken momo is"<<getprice()<<std::endl;
    }
};
int main()
{
    vegmomo v1;
    buffmomo b1;
    chickenmomo c1;
    Momo *ptr;
    ptr = &v1;
    ptr->display_price();
    ptr = &b1;
    ptr->display_price();
    ptr = &c1;
    ptr->display_price();

}