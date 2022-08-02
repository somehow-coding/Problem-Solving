class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = size(nums);
        for(int i=0; i<n-2; i++){
            int j = i+1, k = n - 1;
            // int t = nums[i] + nums[j] + nums[k] = 0.....
            int t = -1 * nums[i];    
            while(j<k){
                if((nums[j] + nums[k]) == t){
                    st.insert({nums[i], nums[j], nums[k]});
                    j++, k--;
                }
                else if(nums[j] + nums[k] > t){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        for(auto &v: st){
            ans.push_back(v);
        }
        return ans;
    }
};