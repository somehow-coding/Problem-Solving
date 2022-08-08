class Solution {
public:
    
    /*
    function returning index of element having value just greater than val
    used binary search algorithm.
    */
    int bs(vector<int> &nums, int start, int end, int val){
        int reti = -1;
        while(start<=end){
            int mid = (start + end) >> 1;
            if(nums[mid]>val){
                reti = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return reti;
    }
    
    /*
    function to reverse elements of the array from index start to index start
    */
    
    void rev(vector<int> &nums, int start, int end){
        while(start<=end){
            swap(nums[start++],nums[end--]);
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int j = size(nums) - 1, i = size(nums) - 2, permutated = 0;
        
        while(i>=0){
            if(nums[i]<nums[i+1]){
                permutated = 1;
                int k = bs(nums, i+1, j, nums[i]);
                swap(nums[k],nums[i]);
                rev(nums, i+1, j);
                break;
            }
            i--;
        }
        if(!permutated){
            rev(nums, 0, j);
        }
    }
};