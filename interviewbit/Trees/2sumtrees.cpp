/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    int i, j, rin = 1, in = 1;
    
    TreeNode *inroot = A,*rinroot = A;
    stack <TreeNode*> instack, rinstack;
    
    while(1){
        while(inroot!=NULL && in!=0){
            instack.push(inroot);
        //    cout<<"Values"<<inroot->val<<"   ";
            inroot = inroot->left;
            
        }
        
        while(rinroot!=NULL && rin!=0){
            rinstack.push(rinroot);
            rinroot = rinroot->right;
        }
        if(instack.empty() && rinstack.empty())
            break;
        inroot = instack.top();
        rinroot = rinstack.top();
        if(inroot == rinroot)
            break;
     //   cout<<inroot->val<<" and "<<rinroot->val<<" ";
        if(inroot->val + rinroot->val == B){
            return 1;
        }
        else if(inroot->val+rinroot->val>B){
            rinstack.pop();
            rinroot = rinroot->left;
            rin = 1;
            in = 0;
        }
        else {
            instack.pop();
            inroot = inroot->right;
            in = 1;
            rin = 0;
        }
    }
    
    return 0;
}
