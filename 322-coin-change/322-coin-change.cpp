class Solution {
public:
    int dp[15][10005];
    
    int fun(vector<int> &coins, int index, int amount){
        if(index==0){
            return (amount==0)?0:INT_MAX-1;
        }
        
        if(dp[index][amount]!=-1) {
            return dp[index][amount];
        }
        
        int mini = INT_MAX;
        if(amount - coins[index-1] >= 0){
            mini = 1 + fun(coins, index, amount - coins[index-1]);
        }
        mini = min(mini, fun(coins, index-1, amount));
        return dp[index][amount] = mini;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int num = fun(coins, coins.size(), amount);
        return num>=INT_MAX-1?-1:num;
    }
};