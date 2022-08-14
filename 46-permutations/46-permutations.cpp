class Solution {
public:
    int factorial(int n){
        if(n==0 or n==1){
            return 1;
        }
        return n * factorial(n-1);
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        cout<<factorial(size(nums));
        for(int i=0;i<factorial(size(nums));i++){
            res.push_back(nums);
            next_permutation(begin(nums),end(nums));
        }
        return res;
    }
};