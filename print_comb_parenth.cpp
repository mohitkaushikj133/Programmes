#include<iostream>
using namespace std;
void balanced(char* a,int n,int open,int close)
{
	if(open+close==2*n)
	{
		for(int i=0;i<2*n;i++) 
		{
			cout<<a[i];
		}
		cout<<endl; return;
	}
	if(open>=close && open<n)
	{ 
		a[open+close]='{';
		balanced(a,n,open+1,close);
	}	
	if(close<open && close<n)
	{
		a[open+close]='}';
		balanced(a,n,open,close+1);
	}
	
}

int main()
{
	int n;
	cin>>n;
	char arr[2*n];
	arr[0]='{';
	balanced(arr,n,1,0);
}
