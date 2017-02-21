#include <iostream>
#include <map>
using namespace std;
struct node //tree node
{
	int data;
	node *left;
	node *right;
};
node* createNode(int data) //create the node
{
	node *head=new node();
	head->data=data;
	head->left=NULL;
	head->right=NULL;
	return head;
}


void topview(node* root, int vlevel,int level,map<int,int>& top,map<int,int>& hor)
{
    if(!root) return ;
    if(top[vlevel]==0)
    {
       // cout<<vlevel<<"vlevel";
    top[vlevel] = root->data;
    hor[vlevel] = level;
    }
    else
    {
        if(level<hor[vlevel])
        {
            top[vlevel] = root->data;
        }
    }
    topview(root->left,vlevel-1,level+1,top,hor);
    topview(root->right,vlevel+1,level+1,top,hor);
}
void top_aux(node* root)
{
    map<int,int>top;
    map<int,int>hor;
    int vlevel = 0,level=1;
    topview(root,vlevel,level,top,hor);
    map<int,int>::iterator it;
    for(it=top.begin();it!=top.end();it++)
    {
        cout <<it->second;
    }
}

int main()
{
node* root = createNode(1);
root->right = createNode(2);
root->right->left = createNode(3);
root->right->left->left = createNode(4);
root->right->right = createNode(5);
root->right->right->left = createNode(6);
root->right->right->left->left = createNode(7);
top_aux(root);
return 0;
}


