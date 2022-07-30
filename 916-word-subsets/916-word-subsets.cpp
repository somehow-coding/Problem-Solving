class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        unordered_map<char,int> mp, m, mp2;
        for(string &s: words2){
            for(char c: s){
                m[c]++;
            }
            for(char c='a'; c<='z'; c++){
                mp[c] = max(mp[c], m[c]);    
                m[c] = 0;
            }
        }
        for(string &s: words1){
            int insert = 1;
            for(char c: s){
                mp2[c]++;
            }
            for(char c='a'; c<='z'; c++){
                if(mp2[c]<mp[c]){
                    insert = 0;
                }
                mp2[c] = 0;
            }
            if(insert){
                res.push_back(s);
            }
        }
        return res;
    }
};