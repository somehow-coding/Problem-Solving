class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0; i<size(s); i++){
            if(!(size(st))){
                st.push(s[i]);
                continue;
            }
            if(st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        int n = st.size();
        string res(n--,'o');
        while(st.size()){
            res[n--] = st.top(); st.pop();
        }
        return res;
    }
};