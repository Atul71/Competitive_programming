/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode *root, TreeNode **first, TreeNode **prev, TreeNode **last){
        if(root==NULL)
            return;
        inorder(root->left, first, prev, last);
        if(*prev!=NULL && (*prev)->val > root->val){
            
            if(*first==NULL){
                
                *first = *prev;
            }
            *last = root;
            
        }
        *prev = root;
        inorder(root->right, first, prev, last);
    }
    void recoverTree(TreeNode* root) {
        vector <int> r(2);
        TreeNode *first=NULL, *prev=NULL, *last = NULL;
        inorder(root, &first, &prev, &last);
        int temp;
        
        temp = first->val;
        first->val = last->val;
        last->val = temp;
    }
};