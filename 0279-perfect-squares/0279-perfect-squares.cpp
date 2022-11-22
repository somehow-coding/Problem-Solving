class Solution {
public:
    // 100l^2 = 10000
    int arr[101];
    int dp[101][10001];
    
    void fill() {
        for(int i=1;i<101;i++) {
            arr[i] = i * i;
        }
        memset(dp, -1, sizeof(dp));
    }
    
    int fun(int i, int k) {
        if(i==101) {
            if(k==0) return 0;
            return 1e5;
        }
        if(dp[i][k]!=-1) {
            return dp[i][k];
        }
        int cnt = 1e5;
        if(k-arr[i]>=0) {
            cnt = 1 + fun(i, k-arr[i]);
        }

        cnt = min(cnt, fun(i+1, k));

        return dp[i][k] = cnt;
    }
    
    int numSquares(int n) {
        fill();
        return fun(1, n);
    }
};
