class Solution {
public:
    //logic:
    /*
    let say we go through the string s and we have the string str which is the 
    desired string we need to find.
    we need to decide either this character we have to take it or not to complete the str.
    so how we decide?? based on conditions:
    suppose we have not taken the character yet.
    so let say we take it so suppose it is smaller character then previous characters
    if we need lexicographical order we have to remove the previous characters such that
    we should have them in the string ahead.
    
    if we have the character allready then it must be best lexicographical order uptill now.
    we don't do anything.
    */
    //How stack is helping?? 
    /*
    suppose instead of stack we take a string str, which is storing characters.
    so the logic remains the same but deleting smaller characters then previous characters
    can be made easy using stack(o(1) time)
    */
    
    //maps are used as per need.....
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