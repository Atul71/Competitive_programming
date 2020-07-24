/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL)
        return A;
    TreeNode *temp = NULL;
    invertTree(A->left);
    invertTree(A->right);
    
    temp = A->left;
    A->left = A->right;
    A->right = temp;
    return A;
}