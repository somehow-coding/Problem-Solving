class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<vector<int>> ans;
        int n = size(nums);
        for(int i=0; i<n; i++){
            int j = i+1, k = n - 1;
            int t = 0;
            while(j<k){
                if((nums[j] + nums[k] + nums[i]) == t){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j<k and nums[j]==nums[j+1]) j++;
                    j++, k--;
                }
                else if(nums[j] + nums[k] + nums[i] > t){
                    k--;
                }
                else{
                    j++;
                }
            }
            while(i<n-1 and nums[i]==nums[i+1])  i++;
        }
        return ans;
    }
};