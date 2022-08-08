class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN, cur_sum = 0;
        for(int num: nums){
            cur_sum += num;
            max_sum = max(max_sum,cur_sum);
            if(cur_sum<0){
                cur_sum = 0;
            }
        }
        return max_sum;
    }
};