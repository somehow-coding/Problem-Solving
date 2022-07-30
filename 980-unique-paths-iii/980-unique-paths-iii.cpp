class Solution {
public:
    int num, m, n;
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    
    void dfs(vector<vector<int>> &grid, int row, int col, int var, int &cnt){
        if(row<0 or col<0 or row>=m or col>=n or grid[row][col]==3 or grid[row][col]==-1){
            return;
        }
        if(grid[row][col]==2){
            if(num==var){
                cnt++;
            }
            return;
        }
        grid[row][col] = 3;
        
        for(auto d: dir){
            int i = row + d[0], j = col + d[1];
            dfs(grid, i, j, var+1, cnt);
        }
        grid[row][col] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        num = 1, m = size(grid), n = size(grid[0]);
        int row, col;
        for(int i = 0; i < size(grid); i++){
            for(int j = 0; j < size(grid[0]); j++){
                if(grid[i][j]==0){
                    num++;   
                }
                if(grid[i][j]==1){
                    row = i, col = j;
                }
            }
        }
        int cnt =0;
        dfs(grid, row, col, 0, cnt);
        return cnt;
    }
};