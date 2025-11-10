#include<iostream>

using namespace std;
class Rectangle{
int len,wid;
public:
Rectangle(int l,int w){
len=l;
wid=w;
cout<<"Constructor called!!\n Rectangle created with length="<<len<<" and width="<<wid<<endl;
}
int area()
{
return len*wid;
}
int perimeter()
{
return 2*len+wid;
}
~Rectangle()
{
cout<<"Destructor called!!\n Rectangle destroyed.."<<endl;
}
};
int main()
{
Rectangle r(10,30);
cout<<"Area of rectangle:"<<r.area()<<endl;
cout<<"perimeter of rectangle:"<<r.perimeter()<<endl;
return 0;
}
