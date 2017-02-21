#include <iostream>
using namespace std;
struct node
{
	int data;
	node* parent;
	node *left,*right;
};
node* getnewnode(int data)
{
	node* temp = new node();
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	temp->data = data;
	return temp;
}
int height(node* root)
{
	if(!root)
		return -1;
	return max(height(root->left),height(root->right))+1;
}
void ll(node* root)
{
	node* curr_root = root;
	node* curr_parent = root->parent;
	node* curr_right = root->left->right;
	

}
void balance(node* root)
{
	if(!root)
		return;
	balance(root->left);
	balance(root->right);
	int lh = height(root->left);
	int rh = height(root->right);
	if(lh-rh>1)
	{
		if(root->left->left)
		{
			//ll
		}
		else if(root->left->right)
		{
			//lr
		}
	}
	else if(lh-rh<-1)
	{
		if(root->right->right)
		{
			//rr
		}
		else if(root->right->left)
		{
			//rl
		}
	}
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
		root->left->parent = root;
	}
	else
	{
		root->right = insert(root->right,data);
		root->right->parent = root;
	}
	return root;
}

void inorder(node* root)
{
	if(!root) return;
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}


int main()
{
	node* root = NULL;
	root = insert(root,5);
	insert(root,6);
	insert(root,3);
	insert(root,7);
	insert(root,4);
	inorder(root);
	return 0;
}