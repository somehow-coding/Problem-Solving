class Solution {
public:
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int n = size(pattern);
        for(string &word: words){
            int i = 0, insert = 1;
            map<char,char> mp, mw;
            while(i<n){
                if(mp.count(word[i])==0 and mw.count(pattern[i])==0){
                    mp[word[i]] = pattern[i];
                    mw[pattern[i]] = '1';
                }
                else{
                    if(mp[word[i]]!=pattern[i]){
                        insert = 0;
                        break;
                    }
                }
                ++i;
            }
            if(insert){
                res.push_back(word);
            }
        }
        return res;
    }
};