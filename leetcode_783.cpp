Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.





  class Solution {
public:
void inorder(TreeNode* root, vector<int> &v){
    if(root==NULL){
        return;
    }
    inorder (root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        int mini=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            mini=min(mini,v[i+1]-v[i]);
        }
        return mini;

        
    }
};
