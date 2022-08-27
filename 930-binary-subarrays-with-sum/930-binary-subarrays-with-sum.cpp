class Solution {
public:
    /*
    // 1 0 1 0 1 goal 2
       1 1 2 
    // 1
    */
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, cnt = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int index=0; index<nums.size(); index++){
            sum += nums[index];
            cnt += mp[sum-goal];
            mp[sum]++;
        }
        return cnt;
    }
};