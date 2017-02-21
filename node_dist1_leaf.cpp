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

int node_dist1_leaf(node* root,int k)
{
	if(!root)
		return INT_MAX;
	if(root->left==NULL&&root->right==NULL)
	{
		if(k==0)
		{
			cout<<root->data<<" ";		
		}
		return 1;
		
	}
	int lh = node_dist1_leaf(root->left,k);
	int rh = node_dist1_leaf(root->right,k);
	int dist = (lh>rh)?rh:lh;
	if(k==lh||k==rh)
	{
		cout<<root->data<<" ";
	}
	return dist+1;

}
int main()
{
    node *root = getnewnode(1);
    root->left = getnewnode(2);
    root->right = getnewnode(3);
    root->left->left = getnewnode(4);
    root->left->right = getnewnode(5);
    root->left->left->left = getnewnode(8);
 	node_dist1_leaf(root,0);
    return 0;
}