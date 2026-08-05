#include<iostream>

class Height{
private:
    int meters;
    int cm;

public:
    Height() {
        meters = 0;
        cm = 0;
    }

    Height(int m, int c) : meters(m), cm(c) {
        if (cm >= 100) {
            meters += cm / 100;  
            cm = cm % 100;
        }
    }

    friend Height operator-(Height h1, Height h2);

    void display() {
        std::cout << "The height is " << meters 
                  << " meters and " << cm << " cm" << std::endl;
    }
};

Height operator-(Height h1, Height h2){
    Height temp;

    temp.meters = h1.meters - h2.meters;
    temp.cm = h1.cm - h2.cm;

    
    if (temp.cm < 0) {
        temp.meters -= 1;
        temp.cm += 100;
    }

    return temp;
}

int main()
{
    Height mounteverest(8848, 86);
    Height basecamp(1111, 444);

    Height distance;
    distance = mounteverest - basecamp;

    distance.display();   

    return 0;
}