class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,int>> Q;
        Q.push({root, 0});
        map<int,vector<int>> mp;
        vector<vector<int>> ret;
        while(Q.size()){
            int n = Q.size();
            map<int,vector<int>> m;
            while(n--){
                TreeNode* node = Q.front().first;
                int axis = Q.front().second;
                Q.pop();
                m[axis].push_back(node->val);
                if(node->left) Q.push({node->left, axis-1});
                if(node->right) Q.push({node->right, axis+1});
            }
            for(auto &it : m){
                cout<<it.first<<" ";
                sort(it.second.begin(),it.second.end());
                for(int x: it.second){
                    mp[it.first].push_back(x);
                }
            }
            cout<<endl;
        }
        for(auto &it: mp){
            ret.push_back(it.second);
        }
        return ret;
    }
};