Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.




  class Solution {
public:
    int findposition(vector<int> inorder,int element)
    {
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==element)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* tree(vector<int> preorder, vector<int> inorder,int &preindex,int inorderstart,int inorderend)
    {
        if(preindex>=preorder.size()  || inorderstart>inorderend)
        {
            return NULL;
        }
        int element=preorder[preindex++];
        TreeNode* root=new TreeNode(element);
        int pos=findposition(inorder,element);

        root->left=tree(preorder,inorder,preindex,inorderstart,pos-1);
        root->right=tree(preorder,inorder,preindex,pos+1,inorderend);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex=0;
        int inorderstart=0;
        int inorderend=inorder.size()-1;
        return tree(preorder,inorder,preindex,inorderstart,inorderend);
    
        
    }
};
