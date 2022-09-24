class Solution {
public:
    vector<vector<int>> ans;
    
    void fun(TreeNode* root, vector<int> &values, int sum) {
        if(!root) return;
        
        values.push_back(root->val);
        
        sum -= root->val;
        
        if(!root->left and !root->right) {
            if(!sum) ans.push_back(values);
        }
        
        fun(root->left, values, sum);
        
        fun(root->right, values, sum);
        
        values.pop_back();
        
        sum += root->val;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> values;
        
        fun(root, values, targetSum);
        
        return ans;
    }
};