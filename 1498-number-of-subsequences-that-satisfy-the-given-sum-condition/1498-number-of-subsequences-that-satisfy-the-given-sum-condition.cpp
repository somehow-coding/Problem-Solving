class Solution {
public:
    // Intitution:
    /*
    suppose we have an array nums, here we are required to find no of non-empty subsequences,
    such that minimum and maximum element on it is less or equal to target..
    
    although we are given a subsequence thing but after careful obeservation it can found that
    if we sort the nums, even than the ans will the same.
    
    It is working because we only required to have subsequences's min and max element and within
    it(subsequence) even if the element are not in order the ans will be same.
    
    good example : A[] = [5, 3, 7, 6] and sorted A[] = [3, 5, 6, 7]
    
    */
    //logic to find ans
    /*
    let say we sort the nums and for every element we find the no of elements that are less than or
    equal to (target-element) we can find no of such subsequences........
    */
    
    
    int mod = 1e9+7;
    
    //brute force
    /*
    int fun(vector<int> &nums, int i, int maxe, int mine, int target){
        if(i==size(nums)){
            if(maxe!=INT_MIN and mine!=INT_MAX and maxe+mine<=target){
                return 1;
            }
            return 0;
        }
        int ret = 0;
        ret = (ret + fun(nums, i+1, maxe, mine, target))%mod;
        maxe = max(maxe, nums[i]), mine = min(mine, nums[i]);
        ret = (ret + fun(nums, i+1, maxe, mine, target))%mod;
        return ret;
    }*/
    
     
    unsigned long long power(unsigned long long x, unsigned long long y, int p){
        unsigned long long res = 1;
        x = x%p;
        while (y > 0) {
            if (y % 2 == 1)
                res = (res * x)%p;
            y = y >> 1;
            x = (x * x)%p;
        }
        return res % p;
    }
    
    int bs(vector<int> &nums, int I, int x){
        int i=I, j=size(nums)-1, m, r=-1;
        while(i<=j){
            m = (i + j)/2;
            if(nums[m]<=x){
                r = m;
                i = m + 1;
            }
            else{
                j = m - 1;
            }
        }
        return r;
    }
    
    
    int numSubseq(vector<int>& nums, int target) {
        // return fun(nums, 0, INT_MIN, INT_MAX, target);
        
        sort(begin(nums),end(nums));
        
        int ans = 0;
        
        for(int i=0; i<size(nums); i++){
            int j = bs(nums, i, target-nums[i]);
            if(j!=-1){
                j -= i;
                ans = (ans + power(2, j, 1e9+7))%mod;
            }
        }
        return ans;
    }
};