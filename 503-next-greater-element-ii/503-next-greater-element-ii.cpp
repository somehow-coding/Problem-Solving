class Solution {
public:
    // 1,2,3,4,3
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        // for(int i = 0; i < n; i++){
        //     nums.push_back(nums[i]);
        // }
        stack<int> st;
        for(int i = 0; i < 2 * n; i++){
            while(st.size() and nums[st.top()%n] < nums[i%n]){
                ret[st.top()%n] = nums[i%n];
                st.pop();
            }
            st.push(i);
        }
        return ret;
    }
};