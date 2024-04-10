Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.






class Solution {
public:
void convertTree(TreeNode* &root,int &sum){
    if(root==NULL) return;
    convertTree(root->left,sum);
    int currNodeVal = root->val;
    root->val = sum;
    sum-=currNodeVal;
    convertTree(root->right,sum);
}

int getsum(TreeNode* root){
    if(root==NULL) return 0;
    return getsum(root->left) + root->val + getsum(root->right);
}
    TreeNode* bstToGst(TreeNode* root) {
        int nodesum =getsum(root);
        convertTree(root,nodesum);
        return root;


        
    }
};
