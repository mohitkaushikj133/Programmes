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

int diameter(node* root,int *height)
{
	if(!root)
	{
		return *height = NULL;
	}
	int ld=0,rd=0,lh=0,rh=0;
	ld=diameter(root->left,&lh);
	rd=diameter(root->right,&rh);
	*height = max(lh,rh)+1;
	int dia = ld>rd?ld:rd;
	return max(dia,lh+rh+1);
}
int main()
{
    node *root = getnewnode(1);
    root->left = getnewnode(2);
    root->right = getnewnode(3);
    root->left->left = getnewnode(4);
    root->left->right = getnewnode(5);
    root->left->left->left = getnewnode(8);
    int height=0;
 	cout<<diameter(root,&height);
    return 0;
}