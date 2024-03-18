A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.







  class Solution {
public:
void check(TreeNode*root,vector<int>&m){
    if(root==NULL)
        return;
        m.push_back(root->val);
        check(root->left,m);
        check(root->right,m);

}
    bool isUnivalTree(TreeNode* root) {
        vector<int>m;
        int x=root->val;
        check(root,m);
        for(auto k:m){
            if(k!=x)return false;
        }
        return true;
        
        
    }
};
