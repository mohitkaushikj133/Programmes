#include<iostream>
using namespace std;
void balanced(int arr[],int i,int n,int o,int c )
{
	if(i==n)
	{
		for(int i=0;i<n;i++)
		{
		
			cout<<arr[i];
		}
		cout<<endl;
		return;
	}
	if(i==0)
	{
	arr[i]=-1;
	o++;
	i++;
	}
  
	if(o>=c)
	{
		arr[i]=1;
		i++;
		c++;
			balanced(arr+1,i,n,o,c);
		
	}
	if(o<n/2)
	{
		arr[i]=-1;
		i++;
		o++;
		
			balanced(arr+1,i,n,o,c);
		
	}

	
}
int balance_paranthesis_aux(int n)
{
	
	int arr[2*n];
	balanced(arr,0,2*n,0,0);
}
int main()
{
	int n;
	cin>>n;
	balance_paranthesis_aux(n);
}
