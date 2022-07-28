class Solution {
public:
    char opp(char c){
        if(c=='(') return ')';
        else if(c=='{') return '}';
        return ']';
    }
    
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(!st.size()){
                st.push(c);
            }
            else{
                if(opp(st.top())==c){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
        }
        return st.size()==0;
    }
};