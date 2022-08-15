class Solution {
public:  
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = size(nums) - 1;
        while(low<high){
            int mid = (low + high) >> 1;
            bool isOdd = mid%2;
            //mid is odd.
            if(isOdd){
                if(nums[mid-1]==nums[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            //mid is even.
            else{
                if(nums[mid-1]==nums[mid]){
                    high = mid-2;
                }
                else{
                    low = mid;
                }
            }
        }
        return nums[low];
    }
};