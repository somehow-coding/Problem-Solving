class Solution {
public:
    /*
    we maintain a max_sum and cur_sum.
    we add this value of element to cur_sum and update the max_sum.
    
    it makes no sense to keep elements which sums up to a negative value,
    so we slide(update cur_sum to zero)
    
    */
    
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