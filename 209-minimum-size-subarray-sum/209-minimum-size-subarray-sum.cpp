class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, l = INT_MAX;
        long s = 0;
        while(i<size(nums)){
            s += nums[i];
            while(j <= i and s>=target){
                s -= nums[j];
                l = min(l, i-j+1);
                j++;
            }
            i++;
        }
        return l==INT_MAX?0:l;
    }
};