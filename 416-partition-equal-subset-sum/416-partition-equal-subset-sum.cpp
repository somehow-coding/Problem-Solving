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
        
        memset(dp, -1, sizeof(dp));
        return fun(nums, nums.size(), sum/2);
    }
};