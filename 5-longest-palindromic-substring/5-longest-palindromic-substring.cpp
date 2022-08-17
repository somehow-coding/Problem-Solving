class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        res += s[0];
        int dp[n][n],i,j,k;
        for(i=0,j=0;i<n;i++,j++){
            dp[i][j] = 1;
        }
        for(i=0,j=1;j<n;i++,j++){
            dp[i][j] = (s[i]==s[j]);
            if(dp[i][j] and res.size()<(j-i+1)){
                res = s.substr(i,j-i+1);
            }
        }
        for(k=2;k<n;k++){
            for(i=0,j=k;j<n;j++,i++){
                dp[i][j] = (s[i]==s[j]) & (dp[i+1][j-1]);
                if(dp[i][j] and res.size()<(j-i+1)){
                    res = s.substr(i,j-i+1);
                }
            }
        }
        return res;
    }
};