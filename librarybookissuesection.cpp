#include<iostream>
using namespace std;
class Book{
    protected:
    string name;
    string author;
    public:
    Book(){}
    Book(string n,string a):name(n),author(a){}
    //abstract class-pure virtual function
    virtual void display()=0;


};
class Reference:public Book{
    private:
    string genre;
    int latereturn;
    float fine;
    public:
    Reference(){}
    Reference(string n,string a,string g,int l):Book(n,a),genre(g),latereturn(l){}
    void calcfine()
    {
        if(latereturn>1)
        {
            fine=(latereturn-1)*5;
        }
    
    else{
        fine=0;
    }
}
void display() override
{
    cout<<"the total fine for the reference book is :"<<fine<<endl;
}


};
class Issuable_book:public Book{
    private:
    string genre;
    int latereturn;
    float fine;
    
 int issueid;
  static int counter;
    public:
    Issuable_book(){}
    Issuable_book(string n,string a,string g,int l):Book(n,a),genre(g),latereturn(l){
        issueid=++counter;
        calcfine();
    }
    
    void calcfine()
    {
        if(latereturn>30)
        {
            fine=(latereturn-30)*5;
        }
    
    else{
        fine=0;
    }

}

void display() override{
    cout<<"-------Issuable books-------"<<endl;
    cout<<"issueid"<<issueid;
    cout<<"name"<<name;
    cout<<"author"<<author;
    cout<<"genre"<<genre;
    cout<<"late vako din haru"<<latereturn;
    cout<<"late vako din haru ko fine"<<fine;




}



};
 int Issuable_book::counter=0;
int main()
{
   Book *a;
   Book *b;
  
   a=new Issuable_book("c++ ","Bjarene stroustrup","Programming",60);
   a->display();
   
   b=new Reference("data structutre and algorithm","kismatthapa ","programming",3);
   b->display();
   delete a;
   delete b;
   a=0;
   b=0;




}
