Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.





  class Solution {
public:

int i=0;
TreeNode* builtBST(vector<int> & preorder,int start,int end){
    if(start>end) return NULL;
    int curr=preorder[i];
    TreeNode* root=new TreeNode(preorder[i++]);
    int j;
    for(j=i;j<preorder.size();j++){
        if(preorder[j]>curr) break;

    }
    root->left=builtBST(preorder,i,j-1);
    root->right=builtBST(preorder,j,end);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return builtBST(preorder,0,preorder.size()-1);
        

        
    }
};






