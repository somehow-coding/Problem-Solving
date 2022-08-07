class Solution {
public:
    int N, mod = 1e9+7; 
    
    int dp[20005][6];
    
    unordered_map<char,set<char>> mp;
    unordered_map<char,int> val;
    int cntFun(int i, char p){
        if(i==N){
            return 1;
        }
        if(dp[i][val[p]]!=-1){
            return dp[i][val[p]];
        }
        int cnt = 0;
        for(char c:"aeiou"){
            if(mp[p].count(c)){
                cnt = (cnt + cntFun(i+1,c))%mod;
            }
        }
        return dp[i][val[p]] = cnt;
    }
    
    int countVowelPermutation(int n) {
        mp['A'] = {'a','i','e','o','u'};
        val['A'] = 0,
        val['a'] = 1,
        val['i'] = 2,
        val['e'] = 3,
        val['o'] = 4,
        val['u'] = 5,
        mp['a'] = {'e'}, mp['e'] = {'a','i'}, mp['i'] = {'a','e','o','u'};
        mp['o'] = {'i', 'u'}, mp['u'] = {'a'};
        N = n;
        memset(dp,-1,sizeof(dp));
        return cntFun(0, 'A');
    }
};