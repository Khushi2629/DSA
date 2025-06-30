Given the root of a binary tree, return the preorder traversal of its nodes' values.



  class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;

        while(!st.empty() || root){
            while(root){
                ans.push_back(root->val);
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            root=root->right;
        }
        return ans;
        
    }
};
