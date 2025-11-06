#include<iostream>
using namespace std;

int area(int);
int area(int,int);
float area(float);
float area(float,float);

int main()
{
int s,l,b;
float r,bs,ht;
cout<<"enter side of square:"<<endl;
cin>>s;
cout<<"enter length and breadth of rectangle:"<<endl;
cin>>l>>b;
cout<<"enter radius of circle:"<<endl;
cin>>r;
cout<<"Enter base and height of traingle:"<<endl;
cin>>bs>>ht;
cout<<"Area of square:"<<area(s)<<endl;
cout<<"Area of Rectangle:"<<area(l,b)<<endl;
cout<<"Area of Triangle:"<<area(bs,ht)<<endl;
cout<<"Area of circle:"<<area(r)<<endl;
}
int area(int s)
{
return (s*s);
}
int area(int l,int b)
{
return (l*b);
}
float area(float r)
{
return (3.14*r*r);
}
float area(float bs,float ht)
{
return (0.5*bs*ht);
}

