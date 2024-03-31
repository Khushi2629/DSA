Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.






  class Solution {
public:
TreeNode* helper(TreeNode* root) {
  
        if(root -> left == NULL && root -> right == NULL) {
            return NULL;
        } else if (root -> left == NULL) {
            return root -> right;
        } else if  (root -> right == NULL) {
            return root -> left;
        } else {
            
            TreeNode* leftRightMost = root -> left;
            while(leftRightMost -> right != NULL) {
                leftRightMost = leftRightMost -> right;
            }

            leftRightMost -> right = root -> right;

            return root -> left;

        }

    }


    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL) return NULL;

        if(root -> val == key) {
            return helper(root);
        }
        
        TreeNode* dummy = root;

        while(root != NULL) {
            if(root -> val > key) {
                if(root -> left !=  NULL && root -> left -> val == key) {
                    root -> left = helper(root -> left);
                    break;
                } else {
                    root = root -> left;
                }
            } else {
                if(root -> right != NULL && root -> right -> val == key) {
                    root -> right = helper(root -> right);
                    break;
                } else {
                    root = root -> right;
                }
            }
        }

        return dummy;

    }




};

   
  
