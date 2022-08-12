class Solution {
public:
    
    // [0, 1, 1, 2, 3, 3]..
    // [0, 1, 2, 3]..
    int removeDuplicates(vector<int>& nums) {
        int left = 1, right = 1;
        while(right<size(nums)){
            if(nums[right]==nums[right-1]){
                right++;
            }
            else{
                if(left==right){
                    left++, right++;
                }
                else{
                    nums[left++] = nums[right++];
                }
            }
        }
        return left;
    }
};