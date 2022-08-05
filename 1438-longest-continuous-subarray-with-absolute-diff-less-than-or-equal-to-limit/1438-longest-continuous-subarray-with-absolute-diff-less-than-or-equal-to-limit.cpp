class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int i =0,j=0, n = size(nums), len=1;
        while(i<n){
            st.insert(nums[i]);
            while(j<n){
                if(*st.rbegin()-*st.begin()<=limit){
                    break;
                }
                else{
                    st.erase(st.find(nums[j]));
                    j++;
                }
            }
            len = max(len, i-j+1);
            i++;
        }
        return len;
    }
};