class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1;
        for(i=1; i<nums.size(); i++) {
            if(nums[i-1] == nums[i]) {
                continue;
            }
            else {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};