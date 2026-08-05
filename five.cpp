    #include<iostream>

    using namespace std;


    int main()
    {
        int chaiSales[3][7]=
        {
        {1,2,23,3,33,33,3},
        {22,33,44,55,22,22,4},
        {1,2,3,4,5,6,7}
        };
        for(int i=0;i<3;i++)
        
            {
                cout<<"i am at"<<i+1;
                for(int j=0;j<7;j++)
                {
                    cout<<chaiSales[i][j]<<"cups";
                        }
            }
            return 0;
    }