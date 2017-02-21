#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};
node* createNode(int data,node *left,node *right)
{
	node *temp=new node();
	temp->data=data;
	temp->left=left;
	temp->right=right;
	return temp;
}

void levelorder(node* head)
{
	queue<node*> Q;
	Q.push(head);
	while(!Q.empty())
	{
		node* f = Q.front();
		Q.pop();
		cout<<f->data<<" ";
		if(f->left)
		{
			Q.push(f->left);
		}
		if(f->right)
		{
			Q.push(f->right);
		}
	}

}
//considering the data does not contain 0
////////////////////////////////////
/// Correct Method
////////////////////////////////////
void right_view(node* root,int level,int vlevel,map<int,int> &ver,map<int,int> &hor)
{
	if(!root)		return ;
	if(ver[level]==0) //considering the data does not contain 0
	{
		ver[level]=root->data;
		hor[level]=vlevel;
	}
	else
	{
		if(vlevel >= hor[level])
		{
			ver[level]=root->data;
			hor[level]=vlevel;
		}
	}

	right_view(root->left,level+1,vlevel-1,ver,hor);
	right_view(root->right,level+1,vlevel+1,ver,hor);

}
void right_aux(node* root)
{
	int vlevel=0,level=1;
	map<int,int>ver;
    map<int,int>hor;
	right_view(root,level,vlevel,ver,hor);
	map<int,int>::iterator it;
    for(it=ver.begin();it!=ver.end();it++)
    {
        cout <<it->second;
    }
}

/*
///////////////////////////////////////////////////////////////
Below method is wrong...................... check btw
///////////////////////////////////////////////////////////////  
void rightView(node* root, int level, int *maxlevel){
    if(root == NULL){
        return;
    }
    if(level > *maxlevel){
        cout<<root->data<<" ";
        *maxlevel = level;
    }
    rightView(root->right, level + 1, maxlevel);
    rightView(root->left, level + 1, maxlevel);
}

void rightViewAux(node* root){
    int level = 1, maxlevel = 0;
    rightView(root, level, &maxlevel);
}*/

int main(){
	node *node9=createNode(9,NULL,NULL);
	node *node8=createNode(8,node9,NULL);
	node *node7=createNode(7,node8,NULL);
	node *node3=createNode(3,node7,NULL);
	node *node6=createNode(6,NULL,NULL);
	node *node5=createNode(5,NULL,node6);
	node *node4=createNode(4,NULL,node5);
	node *node2=createNode(2,NULL,node4);
	node *head=createNode(1,node2,node3);
	//rightViewAux(head);
	right_aux(head);
	cout<<endl;
	levelorder(head);
	return 0;
}