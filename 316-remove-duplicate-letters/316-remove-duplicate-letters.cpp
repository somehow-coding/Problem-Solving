class Solution {
public:
    //lagatar deletions karne ho to stack use karne ka sense banta hai...
    //aabbcc
    string removeDuplicateLetters(string s) {
        map<char,int> totalFreq, curFreq;
        stack<char> st;
        for(char c: s) totalFreq[c]++;
        for(char c: s){
            if(!st.size()){
                st.push(c);
                curFreq[c]++;
            }
            else if(!curFreq[c]){
                while(st.size() and st.top()>=c and totalFreq[st.top()]){
                    curFreq[st.top()]--;
                    st.pop();
                }
                st.push(c), curFreq[c]++;
            }
            totalFreq[c]--;
        }
        string res = "";
        while(st.size()){
            res += st.top();
            st.pop();
        }
        reverse(begin(res),end(res));
        return res;
    }
};