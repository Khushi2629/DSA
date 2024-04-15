Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.












class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int currnum =0;
        int currcnt = 0;
        int currmax=0;
        TreeNode *node=root;
        while(node!= nullptr){
            while ( node->left != nullptr){
                TreeNode *frd=node->left;
                while (frd->right != nullptr) frd =frd->right;
                frd->right = node;
                TreeNode *prev =node;
                node=node->left;
                prev->left =nullptr;
            }
            int num= node->val;
            if (num== currnum){
                currcnt++;
            } else{
                currcnt =1;
                currnum =num;
            }
            if (currcnt > currmax){
                currmax = currcnt;
                ans.clear();
            }
            if (currcnt ==currmax){
                ans.push_back(currnum);
            }
            node =node->right;
        }
        return ans;
        
    }
};
