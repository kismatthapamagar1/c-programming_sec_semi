// Here is a case
// we have to make program to deal with the food order of a restaturant
//Basic requisites:
/* There is a base class called Food
members - string dishname
          double price
another derived class from Food- Table info
        static int table no(unique)
        menu(array)

and finally the derived class Bill amount from the Table info
members- double net amount
        double vatamount
        double gross product  
        
        here we have to implement the run time polymorphism*/
/*#include <iostream>

// Class Food
class Food {
public:
    std::string DishName;
    int Price;

    void inputFood() {
        std::cout << "Enter Dish Name: ";
        std::cin >> DishName;
        std::cout << "Enter Price: ";
        std::cin >> Price;
    }

    void displayFood() {
        std::cout << DishName << " : Rs. " << Price << std::endl;
    }
};

// Base Class TableInfo
class TableInfo {
protected:
    static int TableNo;   // static variable
    int currentTable;     // individual table number
    Food Menu[10];
    int n;

public:
    TableInfo() {
        TableNo++;
        currentTable = TableNo; // assign unique number
    }

    virtual void input() {
        std::cout << "\nTable Number: " << currentTable << std::endl;

        std::cout << "Enter number of dishes: ";
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            std::cout << "\nDish " << i + 1 << ":\n";
            Menu[i].inputFood();
        }
    }

    virtual void displayBill() = 0;
};

// Static member initialization
int TableInfo::TableNo = 0;

// Derived Class BillAmount
class BillAmount : public TableInfo {
private:
    float NetAmt, VAT, ServiceCharge, GrossAmt;

public:
    void displayBill() override {
        NetAmt = 0;

        std::cout << "\n===== Bill for Table " << currentTable << " =====\n";

        for (int i = 0; i < n; i++) {
            Menu[i].displayFood();
            NetAmt += Menu[i].Price;
        }

        VAT = 0.13f * NetAmt;
        ServiceCharge = 0.10f * NetAmt;
        GrossAmt = NetAmt + VAT + ServiceCharge;

        std::cout << "\nNet Amount: Rs. " << NetAmt;
        std::cout << "\nVAT (13%): Rs. " << VAT;
        std::cout << "\nService Charge (10%): Rs. " << ServiceCharge;
        std::cout << "\nGross Amount: Rs. " << GrossAmt << std::endl;
    }
};

// Main Function
int main() {
    TableInfo* t[5];

    for (int i = 0; i < 5; i++) {
        t[i] = new BillAmount();
        std::cout << "\n--- Enter details for Table " << i + 1 << " ---\n";
        t[i]->input();
    }

    for (int i = 0; i < 5; i++) {
        t[i]->displayBill();
        delete t[i];
    }

    return 0;
}*/

#include<iostream>
#include<string>
class Food
{
     public:
    std::string foodname;
    double price;
   
   void food()
   {
    std::cout<<"enter the food name and price of the food"<<std::endl;
    std::cin>>foodname>>price;

   }
   void display()
   {
    std::cout<<"food="<<foodname<<"price=price"<<std::endl;
   }

};
class Tableinfo : public Food{
    protected:
    static int tableNo;
    int table;
    Food menu[10];
    int n;
    public:
    Tableinfo()
    {
        tableNo++;
        table=tableNo;
        
    }
    virtual void inputfood()
    {
        std::cout<<"the table no is"<<tableNo<<std::endl;
        std::cout<<"enter the no of dish you need to order:"<<std::endl;
        std::cin>>n;
        for(int i=0;i<n;i++)
    {
        std::cout<<"the food and their prices in the menu is:"<<std::endl;
        menu[i+1].food();
        
    
    } 
      
}
virtual void displayBill()=0;// virtual function is declared outside other function as it is also an indep funct..

};
    int Tableinfo ::tableNo=0;  
    class Billamount : public Tableinfo{
        private:
        double netamount;
        double vat;
        double servicecharge;
        double grossamount;
        public:
        void displayBill() override
        {
            netamount=0;
            for(int i=0;i<n;i++)
            {
                netamount=menu[i].price;
            }
            vat=0.13*netamount;
            servicecharge=0.05*netamount;
            grossamount=netamount+vat+servicecharge;
             std::cout << "\nNet Amount: Rs. " << netamount;
        std::cout << "\nVAT (13%): Rs. " << vat;
        std::cout << "\nService Charge (10%): Rs. " << servicecharge;
        std::cout << "\nGross Amount: Rs. " << grossamount << std::endl;
    }

        };
        int main()
        {
            Tableinfo* ptr[5];
            for(int i=0;i<5;i++)
            {
                ptr[i]=new Billamount();
                ptr[i]->inputfood();
            }
            for(int i=0;i<5;i++)
            {
                ptr[i]=new Billamount();
                ptr[i]->display();
                delete ptr[i];
                ptr[i]=0;
            }
            return 0;

            
            
        }


    