class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int i = 0, j = size(nums)-1, cnt = 0;
        while(i<j){
            if(nums[i]+nums[j]==k){
                i++, j--, cnt++;
            }
            else if(nums[i] + nums[j]>k){
                j--;
            }
            else{
                i++;
            }
        }
        return cnt;
    }
};