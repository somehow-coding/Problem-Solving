class Solution {
public:
    int ans = -1;
    void dfs(vector<int>& edges, vector<int>& vis, vector<int>& toVis, vector<int>& dis, int node, int cnt){
        if(vis[node]){
            ans = max(ans, cnt-dis[node]);
            return;
        }
        if(toVis[node]){
            return;
        }
        vis[node] = 1, toVis[node] = 1, dis[node] = cnt;
        if(edges[node]==-1){
            vis[node] = 0;
            dis[node] = 0;
            return;
        }
        dfs(edges, vis, toVis, dis, edges[node], cnt+1);
        dis[node] = 0;
        vis[node] = 0;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = size(edges);
        vector<int> vis(n,0), toVis(n,0), dis(n,0);
        for(int node=0; node<n; node++){
            if(!toVis[node]){
                dfs(edges, vis, toVis, dis, node, 0);
            }
        }
        return ans;
    }
};