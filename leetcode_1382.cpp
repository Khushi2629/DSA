Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.






  class Solution {
public:
void inorderTraversal(TreeNode* root,vector<int>&v) {
        if(root==NULL)
        return;

        inorderTraversal(root->left,v);
        v.push_back(root->val);
        inorderTraversal(root->right,v);
        return;
    }

    TreeNode* build(int i,int j,vector<int>&v){
        if(i>j) return NULL;
        int mid=(i+j)/2;
         TreeNode*newNode=new TreeNode(v[mid]);
         newNode->left=build(i,mid-1,v);
         newNode->right=build(mid+1,j,v);
         return newNode;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
         inorderTraversal(root,v);
        int i=0,j=v.size()-1;

        return build(0,j,v);
    }
};

    
