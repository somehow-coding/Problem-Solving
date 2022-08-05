class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     unordered_map<char,int> m;
    //     int ans = 0, j =0, n = size(s);
    //     for(int i=0; i<size(s); i++){
    //         while(j<i and m[s[i]]>0){
    //             m[s[j++]]--;
    //         }
    //         m[s[i]]++;
    //         ans = max(ans, i-j+1);
    //     }
    //     return ans;
    // }
    
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]-' '] > start)
                start = dict[s[i]-' '];
            dict[s[i]-' '] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};