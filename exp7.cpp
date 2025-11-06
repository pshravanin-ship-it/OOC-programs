#include<iostream>
using namespace std;
class Person
{
public:
Person()
{
cout<<"person's constructor called";
}
};
class Faculty:public Person
{
public:
Faculty()
{
cout<<"Faculty's constructor called";
}
};
class Student:public Person
{
public:
Student()
{
cout<<"Student's constructor called";
}
};
class TA:public Faculty,public Student
{
public:
TA()
{
cout<<"TA's constructor called";
}
};
int main()
{
TA ta;
return 0;
}

