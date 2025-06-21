Given a binary tree, determine if it is height-balanced.




  class Solution {
public:
int checkheight(TreeNode* node){
    if(!node) return 0;
    int left=checkheight(node->left);
    if(left==-1) return -1;
    int right=checkheight(node->right);
    if(right==-1) return -1;
    if(abs(left-right)>1) return -1;

    return 1+ max(left,right);
}
    bool isBalanced(TreeNode* root) {
        return checkheight(root) !=-1;
        
    }
};
