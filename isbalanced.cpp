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

int height(node* root)
{
	if(!root) return 0;
	return (max(height(root->left),height(root->right))+1);
}


//complexity is O(N^2) in worst case - skewed tree 
bool isbalanced(node* root)
{
	if(!root) return true;
	if(abs(height(root->left)-height(root->right))<=1) 
	{
		if(isbalanced(root->left))
		{
			return (isbalanced(root->right));
		}
	}
	return false;

}

//optimized one in O(N)
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
    node *root = getnewnode(1);
    root->left = getnewnode(2);
    root->right = getnewnode(3);
    root->left->left = getnewnode(4);
    root->left->right = getnewnode(5);
    root->left->left->left = getnewnode(8);
 
    cout<<isbalanced(root);

    int height1 = 0;
    cout<<isbalanced_opt(root,&height1);

    return 0;
}