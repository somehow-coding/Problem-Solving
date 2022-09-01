class Solution {
public:
    int dp[205][10005];
    
    bool fun(vector<int> &nums, int index, int sum) {
        if(index == 0) {
            return (sum == 0);
        }
        if(dp[index][sum] != -1) {
            return dp[index][sum];
        }
        bool ret = false;
        if(sum - nums[index - 1] >= 0) {
            ret = fun(nums, index - 1, sum - nums[index - 1]);
        }
        return dp[index][sum] = ret | fun(nums, index - 1, sum);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums),end(nums),0);
        
        if(sum & 1) return false;
        // memset(dp, -1, sizeof(dp));
        // return fun(nums, nums.size(), sum/2);
        sum /= 2;
        
        int n = nums.size(), t[n+1][sum+1];
        
        for(int j = 1; j <= sum; j++) {
            t[0][j] = 0;
        }
        
        for(int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }
        
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(j - nums[i-1] >= 0) {
                    t[i][j] = t[i-1][j-nums[i-1]] | t[i-1][j];
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][sum];
    }
};