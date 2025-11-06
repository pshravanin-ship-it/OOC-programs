#include<iostream>
using namespace std;
class Student{
int roll;
char name[25];
public:
void getdata(){
cout<<"Enter rollno:"<<endl;
cin>>roll;
cout<<"Enter name:"<<endl;
cin>>name;
}
void putdata(){
cout<<"Roll no:"<<roll<<endl;
cout<<"name:"<<name<<endl;
}
};
class StudentExam : public Student
{
public:
int sub1,sub2,sub3,sub4,sub5,sub6;
float per;
void accept()
{
getdata();
cout<<"Enter marks of sub1:"<<endl;
cin>>sub1;
cout<<"Enter marks of sub2:"<<endl;
cin>>sub2;
cout<<"Enter marks of sub3:"<<endl;
cin>>sub3;
cout<<"Enter marks of sub4:"<<endl;
cin>>sub4;
cout<<"Enter marks of sub5:"<<endl;
cin>>sub5;
cout<<"Enter marks of sub6:"<<endl;
cin>>sub6;
}

void display()
{
putdata();
cout<<"Marks of sub1:"<<sub1<<endl;
cout<<"Marks of sub2:"<<sub2<<endl;
cout<<"Marks of sub3:"<<sub3<<endl;
cout<<"Marks of sub4:"<<sub4<<endl;
cout<<"Marks of sub5:"<<sub5<<endl;
cout<<"Marks of sub6:"<<sub6<<endl;
}
};
class Result: public StudentExam
{
public:
float per;
void cal()
{
per=(sub1+sub2+sub3+sub4+sub5+sub6)/6.0;
cout<<"Percentage:"<<per<<endl;
}
};
int main()
{
Result r;
int count,i;
cout<<"enter number of stuednts:"<<endl;
cin>>count;
for(i=0;i<=count;i++)
{
r.accept();
r.display();
r.cal();
}
return 0;
}

