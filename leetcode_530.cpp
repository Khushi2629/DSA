Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.





  class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false){
            TreeNode* curr =q.front();
            q.pop();
            v.push_back(curr->val);
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right !=NULL)
            q.push(curr->right);
        }

        sort(v.begin(),v.end());
        int mini=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            int x=v[i+1]-v[i];
            if(x<mini)
            mini=x;
        }
        return mini;
        
    }
};
