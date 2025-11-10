#include<iostream>
#include<string>
using namespace std;
class Employee{
private:
int no;
string name;
public:
virtual void display()=0{
cout<<"enter emplopyee number:";
cin>>no;
cout<<"Enter employee name:";
cin>>name;
}
virtual void display()=0{
cout<<"Employee number is "<<no<<endl;
cout<<"Employee name is"<<name<<endl;
}
};
class SalariedEmployeee: public Employee
{
private:
double monthlysalary;
public:
void salary()
{
Employee::salary();
cout<<"enter employee monthly salary:"<<endl;
cin>>monthlysalary;
}
 
