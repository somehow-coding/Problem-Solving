class Solution {
public:
    string removeDuplicates(string s) {
        stack<pair<char,int>> st;
        int k = 2;
        for(int i=0; i<size(s); i++){
            if(!(size(st))){
                st.push({s[i],1});
                continue;
            }
            if(st.top().first==s[i]){
                st.push({s[i],st.top().second+1});
            }
            else{
                st.push({s[i],1});
            }
            if(st.top().second==k){
                int n = k;
                while(n--){
                    st.pop();
                }
            }
        }
        int n = st.size();
        string res(n--,'o');
        while(st.size()){
            res[n--] = st.top().first; st.pop();
        }
        return res;
    }
};