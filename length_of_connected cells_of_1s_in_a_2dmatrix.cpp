#include <bits/stdc++.h>
using namespace std;

void binary(vector<int>& a,int n,int k)
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
		for(int j=0;j<k;j++)
		{
				a[n-1]=j;
				binary(a,n-1,k);
		}
	}
}
void binary_aux(int n,int k)
{
	vector<int> a(n);
	binary(a,n,k);
}
int main()
{
	int n,k;
	cin>>n>>k;
	binary_aux(n,k);
	return 0;
}