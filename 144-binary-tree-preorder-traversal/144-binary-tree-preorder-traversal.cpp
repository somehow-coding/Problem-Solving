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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        stack<TreeNode*> st;
        st.push(root);
        vector<int> ret;
        while(st.size()){
            TreeNode* node = st.top(); st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            ret.push_back(node->val);
        }
        return ret;
    }
};