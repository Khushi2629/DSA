Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.






  class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(!root->left && !root->right){     //check if its a leaf node
            return targetSum-root->val==0;   // if a leaf node then check if diff is 0
        }
        targetSum-=root->val;                // “If I’m at a node with value x, then the remaining sum I need to find in the child paths is targetSum - x.”

         return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);     //If either subtree has a valid path, return true.
    }
};
