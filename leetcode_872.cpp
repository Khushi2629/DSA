Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
  For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.





  class Solution {
public:
void solve(TreeNode* root,vector<int>&tree)
{
    if(root==NULL)
    {return;
    }
    solve(root->left,tree);
    solve(root->right,tree);
    if(root->left==NULL && root->right==NULL){
        cout<<root->val;
        tree.push_back(root->val);
    }
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        solve(root1,tree1);
        solve(root2,tree2);

        if(tree1==tree2)return true;
        else return false;
        
    }
};
