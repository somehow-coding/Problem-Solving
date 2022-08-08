class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int i=0;i<size(nums);i++){
            auto it = lower_bound(begin(lis),end(lis),nums[i]);
            if(it!=end(lis)){
                int j = it - begin(lis);
                lis[j] = nums[i];
            }
            else{
                lis.push_back(nums[i]);
            }
        }
        return size(lis);
    }
};