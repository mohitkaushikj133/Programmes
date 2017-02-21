#include <bits/stdc++.h>
using namespace std;

void binary(vector<int>& a,int n)
{
	if(n<=0) 
	{
			vector<int>:: iterator i;
			for(i=a.begin();i!=a.end();i++)
				cout<<*i;
			cout<<endl;
			return;
	}
	else
	{
		a[n-1]=0;
		binary(a,n-1);
		a[n-1]=1;
		binary(a,n-1);
	}
}
void binary_aux(int n)
{
	vector<int> a(n);
	binary(a,n);
}
int main()
{
	int n;
	cin>>n;
	binary_aux(n);
	return 0;
}