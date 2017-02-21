#include <iostream>
#include <climits>
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

int lca(node* root,int n1,int n2)
{
	if(!root)
	{
		return 0;
	}
	if(root->data==n1||root->data==n2)
	{
		return root->data;
	}
	int l = lca(root->left,n1,n2);
	int r = lca(root->right,n1,n2);
	if(l&&r) return root->data;
	return (l!=0)?l:r;
}
int main()
{
    node *root = getnewnode(1);
    root->left = getnewnode(2);
    root->right = getnewnode(3);
    root->left->left = getnewnode(4);
    root->left->right = getnewnode(5);
    root->left->left->left = getnewnode(8);
 	cout<<lca(root,8,5);
    return 0;
}