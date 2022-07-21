class Solution {
public:
    
    TreeNode* fun(TreeNode* root){
        if(!root){
            return NULL;
        }
        TreeNode* lft = fun(root->left);
        TreeNode* rgt = fun(root->right);
        if(!lft){
            root->right = rgt;
            return root;
        }
        TreeNode* ptr = lft;
        while(ptr->right){
            ptr = ptr->right;
        }
        ptr->right= root;
        root->left = NULL;
        root->right = rgt;
        return lft;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        return fun(root);
    }
};