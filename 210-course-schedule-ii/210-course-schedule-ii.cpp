class Graph{
  public:
    vector<vector<int>> graph;
    vector<int> visNodes;
    vector<int> vis;
    vector<int> arr;
    Graph(vector<vector<int>> &edges, int N){
        graph.resize(N);
        vis.resize(N,0);
        visNodes.resize(N,0);
        for(vector<int> edge: edges){
            graph[edge[0]].push_back(edge[1]);
        }
    }
};

class Solution {
public:
    bool dfs(Graph &g, int i){
        if(g.vis[i]){
            return true;
        }
        if(g.visNodes[i]){
            return false;
        }
        g.vis[i] = 1;
        g.visNodes[i] = 1;
        for(int j: g.graph[i]){
            if(dfs(g,j)){
                return true;
            }
        }
        g.arr.push_back(i);
        g.vis[i] = 0;
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(prerequisites, numCourses);
        for(int i=0; i<numCourses; i++){
            if(!g.visNodes[i]){
                if(dfs(g,i)){
                    return {};
                }
            }
        }
        return g.arr;
    }
};