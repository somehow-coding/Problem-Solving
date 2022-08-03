class Solution {
public:
    vector<int> safeNodes;
    
    bool dfs(vector<vector<int>> &graph, int node, vector<int> &vis){
        if(vis[node]){
            if(safeNodes[node]==-1) return false;
            return safeNodes[node];
        }
        vis[node] = 1;
        bool safe = 1;
        for(auto a: graph[node]){
            safe &= dfs(graph, a, vis);
        }
        // cout<<safe<<" "<<node<<endl;
        safeNodes[node] = safe;
        return safe;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(size(graph),0);
        safeNodes.resize(size(graph),-1);
        vector<int> ans;
        for(int i=0; i<size(graph); i++){
            if(!vis[i]){
                dfs(graph, i, vis);
            }
            if(safeNodes[i]) ans.push_back(i);
        }
        return ans;
    }
};