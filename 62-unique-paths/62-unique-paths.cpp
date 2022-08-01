class Solution {
public:
    int dp[101][101];
    
    int fun(int i, int j, int m, int n){
        if(i==m-1 and j==n-1){
            return 1;
        }
        if(i==m or j==n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ret = 0;
        ret += fun(i+1, j, m, n);
        ret += fun(i, j+1, m, n);
        return dp[i][j] = ret;
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, m, n);
    }
};