class Solution {
public:
    
    long long dp[100001];
    
    long long maxl(long long a, long long b){
        if(a>b) return a;
        return b;
    }
    
    int bs(vector<vector<int>> &rides, int I){
        int i=I+1, j=size(rides)-1, reti=size(rides);
        while(i<=j){
            int m = (i + j) >> 1;
            if(rides[m][0]>=rides[I][1]){
                j = m - 1;
                reti = m;
            }
            else{
                i = m + 1;
            }
        }
        return reti;
    }
    
    long long fun(vector<vector<int>> &rides, int i){
        if(i==size(rides)){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        //we have choice of selecting the ith passenger.....
        //don't take this passenger...
        long long ret = fun(rides, i+1);
        int nexti = bs(rides, i);
        // let's take this passenger....
        ret = maxl(ret, (rides[i][1]-rides[i][0]+rides[i][2]+fun(rides, nexti)));
        return dp[i] = ret;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(begin(rides),end(rides));
        memset(dp, -1, sizeof(dp));
        return fun(rides, 0);
    }
};