#include<iostream>
using namespace std;
class Number{
int value;
public:
Number(int v=0):value(v){}
Number operator++()
{
return Number(++value);
}
Number operator++(int)
{
return Number(value++);
}
Number operator-()
{
return Number(-value);
}
Number operator+(const Number &obj)
{
return Number(value+obj.value);
}
Number operator-(const Number &obj)
{
return Number(-value);
}
bool operator==(const Number &obj)
{
return value==obj.value;
}
bool operator<(const Number &obj)
{
return value<obj.value;
} 
void show()
{
cout<<value<<endl;
}
};

int main()
{
Number n1(10),n2(5);
cout<<"Binary:";
(n1+n2).show();
cout<<"Unary:";
(++n1).show();
cout<<"Relational:"<<(n1<n2?"n1<n2":"n1>=n2")<<endl;
return 0;
}


