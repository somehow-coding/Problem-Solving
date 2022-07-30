class Solution {
public:
    int dir[4][2] = {{0,-1},{-1,0},{1,0},{0,1}}, m, n;
    
    void dfs(vector<vector<int>> &grid, int i, int j){
        if(i==m or j==n or i<0 or j<0 or grid[i][j]==0 or grid[i][j]==2){
            return;
        }
        grid[i][j] = 2;
        for(int k=0; k<4; k++){
            int ii = i+dir[k][0], jj = j+dir[k][1];
            dfs(grid, ii, jj);
        }
    }
    
    //exploring all paths using dfs and then calculating min flips among one of them will give
    //tle(tc will in exponential in nature).
    
    int bfs(vector<vector<int>> &grid, queue<pair<int,int>> q){
        int flips = 0;
        while(q.size()){
            int t = q.size();
            while(t--){
                pair<int,int> p = q.front(); q.pop();
                for(int k = 0;  k < 4; k++){
                    int i = p.first + dir[k][0], j = p.second + dir[k][1];
                    if(i>=0 and i<m and j>=0 and j<n and grid[i][j]!=1){
                        if(grid[i][j]==2){
                            return flips;
                        }
                        if(grid[i][j]==0){
                            grid[i][j] = 1;
                        }
                        q.push({i, j});
                    }
                }
            }
            flips++;
        }
        return flips;
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        m = size(grid), n = size(grid[0]);
        int stop = false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    dfs(grid, i, j);
                    stop = true;
                    break;
                }
            }
            if(stop) break;
        }
        queue<pair<int,int>> q;
        int flips = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        flips = bfs(grid, q);
        return flips;
    }
};