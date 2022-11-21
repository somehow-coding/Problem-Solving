class Solution {
public:
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int steps = 0;
        queue<pair<int,int>> q;
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> vis(m+1, vector<int>(n+1, 0));
        
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = 1;
        int flag = 0;
        int atentrance = 1;
        while(q.size()) {
            int t = q.size();
            while(t--) {
                auto p = q.front(); q.pop();
                for(int i=0; i<4; i++) {
                    int x = dir[i][0]+p.first, y = dir[i][1]+p.second;
                    if(x<0 or y<0 or x>=m or y>=n) {
                        if(atentrance) continue;
                        flag = 1;
                        break;
                    }
                    if(maze[x][y]=='.' and !vis[x][y]) {
                        vis[x][y] = 1;
                        q.push({x,y});
                    }
                }
            }
            atentrance = 0;
            if(flag) break;
            steps++;
        }
        return (flag)?steps:-1;
    }
};