/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) {
            return nullptr;
        } 
        
        TreeNode* _left = pruneTree(root->left);
        TreeNode* _right = pruneTree(root->right);
        
        root->left = _left;
        root->right = _right;
        
        if(_left == nullptr and _right == nullptr) {
            return (root->val == 1)?root:nullptr;
        }
        
        return root;
    }
};