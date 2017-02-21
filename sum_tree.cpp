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
node* insert(node* root,int data)
{
	if(root==NULL)
	{
		return getnewnode(data);
	}
	if(data<root->data)
	{
		root->left = insert(root->left,data);
	}
	else
		{root->right = insert(root->right,data);}
	return root;
}

int sum_tree(node* root)
{
	if(root==NULL) return 0;
	int sum =0;
	sum+=root->data;
	sum+=sum_tree(root->left);
	sum+=+sum_tree(root->right);
	return sum;
}

int main()
{
	node* root = NULL;
	root = insert(root,5);
	insert(root,6);
	insert(root,3);
	insert(root,7);
	insert(root,4);
	cout<<sum_tree(root);
	return 0;
}