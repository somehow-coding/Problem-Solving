class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int> res;
        int n = size(nums)/3, cnt = 1;
        for(int i=0; i<size(nums);i++){
            if(i==0){
                cnt = 1;
            }
            else if(nums[i-1]!=nums[i]){
                cnt = 1;
            }
            else{
                cnt += 1;
            }
            if(cnt>n and ((i==nums.size()-1) or (nums[i]!=nums[i+1]))){
               res.push_back(nums[i]);
            }
        }
        return res;
    }
};