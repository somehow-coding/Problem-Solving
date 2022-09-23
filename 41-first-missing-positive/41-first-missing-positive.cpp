class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
        
//         int i = 0;
        
//         for(; i < nums.size(); i++) {
//             if(nums[i] > 0) break;
//         }
//         int j = 1, k = -1;
//         for(; i < nums.size(); i++) {
//             if(k == nums[i]) continue;
            
//             if(j != nums[i]) break;
//             k = nums[i], j++;
//         }
        
//         return j;
        
//         unordered_set<int> st;
        
//         for(int i : nums) st.insert(i);
        
//         int i = 1;
        
//         for(int i = 1; i <= 1e5 + 1; i++) {
//             if(st.count(i) == 0) return i;
//         }
        
//         return -1;
        
        
        int N = nums.size();
        
        nums.push_back(0);
        
        int k = 1e6;
        
        for(int i = 0; i < N; i++) {
            if(nums[i] < 0) nums[i] = 0;
            if(nums[i] >= 1e6) nums[i] = 0;
        }

        for(int i = 0; i < N; i++) {
            if(nums[i] % k <= 0 or nums[i] % k > N) continue;
            nums[nums[i] % (k)] = ((nums[nums[i] % k]) % k) + k;
        }
        
        for(int i = 1; i <= N; i++) {
            if(nums[i] < k) return i;
        }
        
        return N + 1;
    }
};