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
    
    vector<TreeNode*> fun(int n){
        if(n==1){
            return {new TreeNode(0)};
        }
        if(n==2){
            return {};
        }
        vector<TreeNode*> ret;
        for(int i=1; i<n; i+=2){
            vector<TreeNode*> l = fun(i);
            vector<TreeNode*> r = fun(n-1-i);
            for(auto &x: l){
                for(auto &y: r){
                    TreeNode* root = new TreeNode(0);
                    root->left = x;
                    root->right = y;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        return fun(n);
    }
};