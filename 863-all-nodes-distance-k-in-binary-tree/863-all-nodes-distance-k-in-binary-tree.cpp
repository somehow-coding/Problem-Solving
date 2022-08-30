class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> par;
    
    vector<int> _nodes;
    
    void traverseNodes(TreeNode* root) {
        if(!root){
            return;
        }
        
        if(root->right) {
            par[root->right] = root;
        }
        
        if(root->left) {
            par[root->left] = root;
        }
        
        traverseNodes(root->left);
        traverseNodes(root->right);
    }
    
    void dfs(TreeNode* node, vector<int> &vis, int dis, int k){
        if(!node or vis[node->val]){
            return;
        }
        
        if(dis==k){
            _nodes.push_back(node->val);
            return;
        }
        
        vis[node->val] = 1;
        
        dfs(node->left, vis, dis + 1, k);
        dfs(node->right, vis, dis + 1, k);
        dfs(par[node], vis, dis + 1, k);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        traverseNodes(root);
        
        vector<int> vis(505,0);
        dfs(target, vis, 0, k);
        
        return _nodes;
    }
};