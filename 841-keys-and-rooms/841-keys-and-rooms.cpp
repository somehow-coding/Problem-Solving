class Solution {
public:
    void dfs(vector<vector<int>> &rooms, int room, vector<int> &vis){
        if(vis[room]){
            return;
        }
        vis[room] = true;
        for(int key: rooms[room]){
            dfs(rooms, key, vis);
        }
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(size(rooms),0);
        dfs(rooms, 0, vis);
        for(int i=0;  i<size(rooms); i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};