#include <iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
node* getnewnode(int data)
{
	node* temp = new node();
	temp->left = NULL;
	temp->right = NULL;
	temp->data = data;
	return temp;
}

int abs(int a)
{
	if(a<0) return -a;
	else return a;
}
int max(int a, int b)
{
  return (a >= b)? a: b;
} 


node* bal_from_arr(int *a,int start,int end)
{
	if(start>end)
		return NULL;
	int mid= (start+end)/2;
	node* root = getnewnode(a[mid]);
	root->left = bal_from_arr(a,start,mid-1);
	root->right = bal_from_arr(a,mid+1,end);
	return root;
}

bool isbalanced_opt(node* root,int* height1)
{
	int lh=0,rh=0,r=0,l=0;
	if(!root) 
		{
			*height1 = 0;return true;
		}

	l = isbalanced_opt(root->left,&lh);
	r = isbalanced_opt(root->right,&rh);
	*height1 = max(lh,rh)+1;
	if(abs(rh-lh)>=2) 
		return false;
	else 
		return l&&r;
}
int main()
{
	int arr[8] = {1,2,3,4,5,6,7,8};
	node* root = bal_from_arr(arr,0,7);
	int height = 0;
	cout<<isbalanced_opt(root,&height);
	return 0;
}