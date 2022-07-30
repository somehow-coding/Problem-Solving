class Solution {
public:
    //0 1 2 3 4
    int fun(vector<long long> &pre, int idx,  long long val, int k){
        int i=0, j=idx, m, ans=-1;
        while(i<=j){
            long long sum = pre[idx];
            m = (i + j)>>1;
            if(m!=0){
                sum -= pre[m-1];
            }
            if(((long long)(idx-m+1)*1LL*val)-sum<=k){
                ans = m;
                j = m - 1;
            }
            else{
                i = m + 1;
            }
        }
        return ans;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        int n = size(nums);
        vector<long long> pre(n);
        sort(begin(nums),end(nums));
        map<int,int> mp;
        for(int x: nums) mp[x]++;
        pre[0] = nums[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + nums[i];
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(mp[nums[i]]==0) continue;
            int j = fun(pre, i-1, nums[i], k);
            if(j!=-1){
                ans = max(ans, i-j+mp[nums[i]]);
            }
            else{
                ans = max(ans, mp[nums[i]]);
            }
            mp[nums[i]] = 0;
        }
        return ans;
    }
};