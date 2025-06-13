Given the root of a binary tree, return the inorder traversal of its nodes' values.




  class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        solve(root,result);
        return result;
        
    }
    void solve(TreeNode* root,vector<int>& result){
        if(root !=nullptr){
            solve(root->left,result);
            result.push_back(root->val);
            solve(root->right,result);
        }
    }
};
