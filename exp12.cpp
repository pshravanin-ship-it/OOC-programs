#include<iostream>
#include<fstream>
using namespace std;
int main()
{
string data;
cout<<"Enter some text:";
getline(cin,data);
ofstream fout("user.txt");
fout<<data;
fout.close();

cout<<"Data written to file successfully";
ifstream fin("user.txt");
cout<<"Reading data from file:"<<endl;
string line;
while(getline(fin,line))
{
cout<<line<<endl;
}
return 0;
}
