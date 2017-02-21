#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */


/* DO NOT MODIFY THIS STRUCTURE */
struct node
{
    int info;
    node* left;
    node* right;
};

void b(node*root,int vlevel,int level,map<int,int> &v,map<int,int> &h)
    {
    if(!root)
        return;
    if(v[vlevel]==0)
        {
    v[vlevel] = root->info;
    h[vlevel] = level;
    }
    else if(v[vlevel]!=0)
        {
        if(h[vlevel]<=level)
            {
            v[vlevel] = root->info;
    h[vlevel] = level;
        }
    }
    b(root->left,vlevel-1,level+1,v,h);
    b(root->right,vlevel+1,level+1,v,h);
}

void bottom_view(node* root)
{
        /* Enter your code here. You are allowed to add more functions if needed, but do not modify the signature of this function */ 
    map<int,int> v;
    map<int,int> h;
    int vlevel = 0;
    int level =1;
    b(root,vlevel,level,v,h);
    map<int,int>:: iterator i;
    for(i=v.begin();i!=v.end();i++)
        {
        cout<<i->second<<" ";
    }
    
}

node* createNode(int data) //create the node
{
	node *head=new node();
	head->info=data;
	head->left=NULL;
	head->right=NULL;
	return head;
} 

int main() {
    node* root = createNode(1);
    root->left = createNode(2);
    root->left->right = createNode(3);
    root->left->right->right = createNode(4);
    root->left->right->right->right = createNode(5);
    root->right = createNode(6);
    root->right->left = createNode(7);
    root->right->left->left = createNode(8);
    root->right->left->left->left = createNode(9);


   bottom_view(root);
    return 0;
}




