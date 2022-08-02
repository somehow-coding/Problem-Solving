class Solution {
public:
    int dp[101][101];
    
    int fun(int m, int n){
        if(m==1 and n==1){
            return 1;
        }
        if(m==0 or n==0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int ret = 0;
        ret += fun(m-1, n);
        ret += fun(m, n-1);
        return dp[m][n] = ret;
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return fun(m, n);
    }
};