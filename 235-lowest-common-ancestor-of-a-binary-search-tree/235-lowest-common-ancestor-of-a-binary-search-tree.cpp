/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        
        TreeNode* lft = lowestCommonAncestor(root->left, p, q);
        TreeNode* rgt = lowestCommonAncestor(root->right, p, q);
        
        if(lft and rgt){
            return root;
        }
        
        if(lft==NULL and rgt){
            if(root==q or root==p){
                return root;
            }
            else return rgt;
        }
        if(rgt==NULL and lft){
            if(root==p or root==q){
                return root;
            }
            else return lft;
        }
        if(lft==NULL and rgt==NULL){
            if(root==p){
                return p;
            }
            if(root==q){
                return q;
            }
        }
        return NULL;
    }
};