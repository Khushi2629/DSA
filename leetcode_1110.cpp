Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.






class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        
        dfs(root, true, to_delete_set, forest);
        return forest;
    }
    
private:
    TreeNode* dfs(TreeNode* node, bool is_root, unordered_set<int>& to_delete_set, vector<TreeNode*>& forest) {
        if (!node) return nullptr;
        
        bool should_delete = to_delete_set.count(node->val);
        
        if (is_root && !should_delete) {
            forest.push_back(node);
        }
        
        node->left = dfs(node->left, should_delete, to_delete_set, forest);
        node->right = dfs(node->right, should_delete, to_delete_set, forest);
        
        return should_delete ? nullptr : node;
        
    }
};
