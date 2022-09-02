class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        vector<double> ret;
        
        while(q.size()) {
            int n = q.size();
            long long sum = 0;
            
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                sum += node->val;
                
                if(node->left) {
                    q.push(node->left);
                }
                
                if(node->right) {
                    q.push(node->right);
                }
            }
            
            ret.push_back((double)sum/n);
        }
        
        return ret;
    }
};