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
    int maxd;
    
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        maxd = max(maxd, lh+rh);
        return (max(lh,rh) + 1);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        maxd = 0;
        height(root);
        return maxd;
    }
};