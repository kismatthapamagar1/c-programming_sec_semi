#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include  <string>
using namespace std;
struct Employee{
    int id;
    string name;
    double salary;
};



void displayEmployee(const Employee& emp){ // there is difference in &Employee and Employee&

    cout<<"iD:"<<emp.id<<",name:"<<emp.name<<"salary $"<<emp.salary<<endl;



}
int main()
{
    vector<Employee> employees={
        {1,"kismat",101},
        {2,"aakriti",102},
        {3,"khushi",103},
        {4,"aman",104},
        {5,"anshu",105}
    };//unnamed function are called lamdas
    sort(employees.begin(),employees.end(),[](const Employee& e1,const Employee& e2){
        return e1.salary>e2.salary;
    });
    cout<<"employees sorted by salary -> highest to lowest/n";
    for_each(employees.begin(),employees.end(),displayEmployee);
    vector<Employee> highEarners;
    


    return 0;
}
