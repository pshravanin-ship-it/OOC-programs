#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> nums={1,100,10,70,100};
	cout<<"Numbers are:";
	for (auto &num:nums)
	{
		cout<<num<<",";
	}
	return 0;
}
