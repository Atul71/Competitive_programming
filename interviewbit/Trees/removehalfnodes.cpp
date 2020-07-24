/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A) {
    TreeNode *newnode;
    if(A == NULL)
        return NULL;
        
    solve(A->left);
    solve(A->right);
    
    if(A->right && A->left)
        return A;
    
    else if(A->left){
        TreeNode *newnode;
        newnode = A->left;
        free(A);
    }
    
    else if(A->right){
        TreeNode *newnode;
        newnode = A->right;
        free(A);
    }
    
    A = newnode;
    
}