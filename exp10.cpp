#include<iostream>
using namespace std;
class Shape
{
public:
virtual void area()
{
cout<<"Area of shape"<<endl;
}
};
class Circle:public Shape{
float radius;
public:
Circle(float r)
{
radius=r;
}
void area() override{
cout<<"Area of circle:"<<3.14*radius*radius<<endl;
}
};
class Rectangle:public Shape
{
public:
float l,b;
Rectangle(float len,float bre)
{
l=len;
bre=b;
}
void area() override{
cout<<"Area of Rectangle:"<<l*b;
}
};
int main()
{
Shape *s;
Circle c(5);
Rectangle r(4.3,7.1);
s=&c;
s->area();
s=&c;
s->area();
return 0;
}
