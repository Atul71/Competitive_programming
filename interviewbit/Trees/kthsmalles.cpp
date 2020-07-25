/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::kthsmallest(TreeNode* A, int B) {
    
    stack <TreeNode*> traversal;
    vector <int> res;
    TreeNode *root = A;
    while(1){
        while(root!=NULL){
            traversal.push(root);
            root = root->left;
        }
        if(traversal.empty())
            break;
        root = traversal.top();
        res.push_back(root->val);
        traversal.pop();
        root = root->right;
    }
    return res[B-1];
}
