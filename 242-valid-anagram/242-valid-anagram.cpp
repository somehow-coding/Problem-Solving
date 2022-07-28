class Solution {
public:
    bool isAnagram(string s, string t) {
        if(size(s)!=size(t)) return false;
        vector<int> mp(26,0);
        for(char c: s) mp[c-'a']++;
        for(char c: t){
            mp[c-'a']--;
            if(mp[c-'a']<0) return false;
        }
        return true;
    }
};