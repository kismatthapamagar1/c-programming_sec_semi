#include<iostream>
#include<string>
using namespace std;
// Abstract class
class Digital_wallet
{
    protected:
    double balance;
    int rewardPoints;
    public:
    Digital_wallet()
    {
        balance=0;
        rewardPoints=0;

    }
    virtual void loadBalance(double amount)=0;
    virtual void makePayment(double amount)=0;
    virtual void showTransaction(int id)=0;


};
class Transaction:public Digital_wallet{
    private:
    int transID[5];
    string transType[5];
    double transAmount[5];
    int count;
    public:
    Transaction()
    {
        count=0;

    }
    void loadBalance(double amount) override{
        balance=balance+amount;
        transID[count%5]=count;
        transType[count%5]="load";
        transAmount[count%5]=amount;
        count++;
    }
    //make a payment
    void makePayment(double amount) override{
        if(amount>balance)
        {
            cout<<"can't make the transaction, due to the insufficient balance"<<endl;
            

        }
        else
        {
            balance=balance-amount;
        }
        //reward logic
        if(amount>2000)
        {
            rewardPoints=rewardPoints=50;
        }
        if(rewardPoints>=1000)
        {
            balance=balance+10;
            rewardPoints=rewardPoints-1000;
        }
        transID[count%5]=count;
        transType[count%5]="payment";
        transAmount[count%5]=amount;
        count++;
        cout<<"payment done:"<<amount<<endl;

    }
    //Display transaction using the run time polymorphism;
    void showTransaction(int id) override
    {
        for(int i=0;i<5;i++)
        {
            if(transID[i]==id)
            {
                cout<<"transaction id:"<<transID[i]<<endl;
                cout<<"type:"<<transType[i]<<endl;
                cout<<"amount:"<<transAmount[i]<<endl;
                cout<<"current balance:"<<balance<<endl;
                cout<<"reward points:"<<rewardPoints<<endl;
                return;
            }
        }
        cout<<"TRANSACTION NOT FOUND!!!"
        ;

    }

};
int main()
{
    Digital_wallet *wallet;
    Transaction t;
    wallet=&t;
    wallet->loadBalance(5000);
    wallet->makePayment(2555);
    wallet->loadBalance(2000);
    wallet->makePayment(1000);
    int id;
    cout<<"enter the transaction id to view";
    cin>>id;
    wallet->showTransaction(id);
    return 0;


}        