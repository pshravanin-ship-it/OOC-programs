#include<iostream>
using namespace std;
class Vehicle
{
public:
Vehicle()
{
cout<<"This is vehicle\n";
}
};
class Fare{
public:
Fare()
{
cout<<"fare of vehicle\n";
}
};
class Car:public Vehicle
{
public:
Car()
{
cout<<"This Vehicle is a car\n";
}
};
class Bus:public Vehicle,public Fare
{
public:
Bus()
{
cout<<"This vehicle is a bus with fare\n";
}
};
int main()
{
Bus obj;
return 0;
}
