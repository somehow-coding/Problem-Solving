class Solution {
public:
    /*
    )()(())())(
    */
    
    int longestValidParentheses(string s) {
        vector<int> nums(s.size(),0);
        stack<pair<char,int>> st;
        for(int i = 0; i < size(s); i++){
            if(!st.size()){
                st.push({s[i], i});
            }
            else{
                if(st.top().first=='(' and s[i]==')'){
                    nums[st.top().second] = -2, nums[i] = 2;
                    st.pop();
                }
                else{
                    st.push({s[i], i});
                }
            }
        }
        int len = 0, cur = 0;
        for(int i = 0; i<size(s); i++){
            if(nums[i]==0){
                cur = 0;
            }
            else if(nums[i]>0){
                cur += nums[i];
                len = max(len, cur);
            }
        }
        return len;
    }
};