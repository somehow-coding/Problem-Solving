class Solution {
public:
    bool areAnagrams(vector<int> &S, vector<int> &P){
        for(int i=0; i<26; i++){
            if(S[i]!=P[i]){
                return false;
            }
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int i = 0, j = 0, n = size(s), m = size(p);
        vector<int> S(26,0), P(26,0);
        for(char c: p){
            P[c-'a']++;
        }
        while(i<n){
            S[s[i]-'a']++;
            if((i-j+1)==m){
                if(areAnagrams(S, P)) res.push_back(j);
                S[s[j++]-'a']--;
            }
            i++;
        }
        return res;
    }
};