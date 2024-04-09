Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.






class Solution {
public:

vector<int>res;
void inorder(TreeNode* p)
{
    if(!p) return;
    inorder(p->left);
    res.push_back(p->val);
    inorder(p->right);
}
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return res[k-1];
    }
        
};
