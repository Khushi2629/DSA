Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.





  class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        int left_height=maxDepth(root->left);
        int right_height=maxDepth(root->right);
        return 1+max(left_height,right_height);

        
        
    }
};
