
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
map <string,int> mp;
mp["one"]=1;
mp["two"]=2;
mp["three"]=3;
map<string,int>::iterator it=mp.begin();
while(it!mp.end())
{
cout<<"key:"<<it->first<<"VAlue:"<<it->second<<endl;
++it;
}
return 0;
}
