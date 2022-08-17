class Solution {
public:
    int strStr(string s, string t) {
        if(t.size()>s.size()){
            return -1;
        }
        int n = s.size();
        for(int i=0;i<n;i++){
            if((n-i)>=t.size() and s[i]==t[0]){
                if(s.substr(i,t.size())==t){
                    return i;
                }
            }
        }
        return -1;
    }
};