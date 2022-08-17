class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s =  strs[0];
        for(string t: strs){
            string p="";
            int n = min(s.size(),t.size());
            for(int i=0;i<n;i++){
                if(s[i]!=t[i]){
                    break;
                }
                p += s[i];
            }
            if(!p.size()) return "";
            s = p;
        }
        return s;
    }
};