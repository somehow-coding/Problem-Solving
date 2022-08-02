class Solution {
public:
    int N;
    
    int fun(vector<vector<int>> &matrix, int val){
        int cnt = 0;
        for(int row = 0; row < N; row++){
            int i=0, j=N-1, k=-1;
            while(i<=j){
                int m = (i + j) >> 1;
                if(matrix[row][m]<=val){
                    k = m;
                    i = m + 1;
                }
                else{
                    j = m - 1;
                }
            }
            cnt += (k + 1);
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = size(matrix);
        N = n;
        int low = matrix[0][0], high = matrix[n-1][n-1], ans = -1;
        while(low<=high){
            int mid = (low + high)>>1;
            int cnt = fun(matrix, mid);
            if(cnt<k){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};