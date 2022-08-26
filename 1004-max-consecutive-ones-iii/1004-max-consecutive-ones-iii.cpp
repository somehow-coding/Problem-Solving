class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flips = 0, maxi = 0, left = 0, right = 0;
        while(right<nums.size()){
            if(nums[right]==0){
                flips++;
            }
            while(flips>k){
                if(nums[left]==0){
                    flips--;
                }
                left++;
            }
            maxi = max(maxi, right-left+1);
            right++;
        }
        return maxi;
    }
};