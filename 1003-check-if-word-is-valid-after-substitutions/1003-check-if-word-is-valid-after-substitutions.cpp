class Solution {
public:
    bool isValid(string s) {
        if(size(s)<3){
            return false;
        }
        //is method se kuch case miss ho rhe hai...............
        // unordered_map<int,set<int>> mp;
        // for(int i=0; i<s.size(); i++){
        //     if(i>0 and s[i-1]=='a' and s[i]=='c'){
        //         return false;
        //     }
        //     mp[s[i]-'a'].insert(i);
        // }
        // for(auto it1 = mp[0].begin(); it1 != mp[0].end(); it1++){
        //     int i = *it1;
        //     if(!mp[1].size() or !mp[2].size()){
        //         return false;
        //     }
        //     auto it2 = mp[1].begin(); 
        //     int j = *it2;
        //     auto it3 = mp[2].begin();
        //     int k = *it3;
        //     if((i<j and j<k) and ((j-i)==1 or (k-j)==1)) {
        //         mp[1].erase(it2);
        //         mp[2].erase(it3);
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // return true;
        
        stack<char> st;
        for(int i=0; i<size(s); i++){
            if(st.size()<2){
                st.push(s[i]);
                continue;
            }
            char t = s[i];
            char s = st.top(); st.pop();
            char f = st.top();
            if(f=='a' and s=='b' and t=='c'){
                st.pop();
            }
            else{
                st.push(s), st.push(t);
            }
        }
        return st.size()==0;
    }
};