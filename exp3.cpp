#include<iostream>
using namespace std;
class SavingAccount{
private:
string accountholder;
int accountno;
double balance;
double interestrate;
public:
SavingAccount(string name,int accno,double initialbalance,double rate)
{
accountholder=name;
accountno=accno;
balance=initialbalance;
interestrate=rate;
}
void deposit(double amount)
{
if(amount>0)
{
balance+=amount;
cout<<"Deposited:"<<amount<<endl;
}
}
void withdraw(double amount){
if(amount>0 && amount<=balance)
{
balance-=amount;
cout<<"Withdrawn:"<<amount<<endl;
}
else{
cout<<"Insufficient balance.."<<endl;
}
}
void applyinterest()
{
double interest=balance*interestrate/100;
balance+=interest;
cout<<"Interest Applied:"<<interest<<endl;
}
void display(){
cout<<"\nSavings Account"<<endl;
cout<<"Account Holder:"<<accountholder<<endl;
cout<<"Account number:"<<accountno<<endl;
cout<<"Balance:"<<balance<<endl;
cout<<"Interest Rate:"<<interestrate<<endl;
}
};



class CheckingAccount{
private:
string accountholder;
int accountno;
double balance;
double transactionfee;
public:
CheckingAccount(string name,int accno,double initialbalance,double fee)
{
accountholder=name;
accountno=accno;
balance=initialbalance;
transactionfee=fee;
}
void deposit(double amount){
if(amount>0)
{
cout<<"Deposited:"<<amount<<endl;
}
}
void withdrawn(double amount)
{
double total=amount+transactionfee;
if(total<=balance){
balance-=total;
cout<<"Withdrawn:"<<amount<<"($"<<transactionfee<<"fee applied)"<<endl;
}
else{
cout<<"Insufficient balance for withdrawal + fee"<<endl;
}
}
void display()
{
cout<<"Checking Account:"<<endl;
cout<<"Account Holder:"<<accountholder<<endl;
cout<<"Account number:"<<accountno<<endl;
cout<<"Balance:"<<balance<<endl;
cout<<"Transaction fee:"<<transactionfee<<endl;
}
};
int main()
{
SavingAccount s("ALice",10001,50000,3.4);
CheckingAccount c("Bob",10002,3000,20.0);

s.deposit(450);
s.withdraw(500);
s.applyinterest();
s.display();


c.deposit(2000);
c.withdrawn(1000);
c.display();

return 0;
}



















