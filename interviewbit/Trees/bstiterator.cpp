/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack <TreeNode*> traversal;
TreeNode *cur;
int start = 1;
BSTIterator::BSTIterator(TreeNode *root) {
    cur = root;
    
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    
    if(cur == NULL && traversal.empty())
        return false;
    else
        return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    int value;
    while(cur!=NULL){
        traversal.push(cur);
        cur = cur->left;
    }
    cur = traversal.top();
    value = cur->val;
    traversal.pop();
    
    cur = cur->right;
    return value;
    
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */