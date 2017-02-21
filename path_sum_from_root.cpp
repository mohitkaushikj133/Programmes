#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left,*right;
};
int hasPathSum(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!A)
    return 0;
    if(B==0 && A->left->val==-1  && A->right->val==-1 )
    {
        return 1;
    }
   
    return (hasPathSum(A->left,B-(A->val)) | hasPathSum(A->right,B-(A->val)));
}
TreeNode* createnode(int data)
{
    TreeNode* temp = new TreeNode;
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int main()
{
    TreeNode* root = NULL;
    root=createnode(1000);
    root->left = createnode(2000);
    root->left->left = createnode(-1);
    root->left->right = createnode(-3001);
    root->right = createnode(-1);
    root->right->left = createnode(-1);
    root->right->right = createnode(-1);
    cout<<hasPathSum(root,-1);
}