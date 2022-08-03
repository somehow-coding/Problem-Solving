class cmpr{
        public:
        map<char,int> m;
        cmpr(map<char,int> &mp){
            m = mp;
        }
        
        bool operator()(char &a, char &b){
            return m[a]<m[b];
        }  
};

class Solution {
public:
    map<char,int> mp;
    
    string customSortString(string order, string s) {
        for(int i=0; i<order.size(); i++){
            mp[order[i]] = i;
        }
        for(char c='a'; c<='z'; c++){
            if(!mp.count(c)){
                mp[c] = 26;
            }
        }
        sort(begin(s),end(s),cmpr(mp));
        return s;
    }
};