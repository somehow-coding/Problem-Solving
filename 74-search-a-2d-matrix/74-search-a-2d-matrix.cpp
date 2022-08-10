class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //O(m*n) appraoch is simple
        //O(m*(logn)) approach is better.
        //but we can do it in O(log(m*n)).
        int m = size(matrix), n = size(matrix[0]);
        int low = 0, high = m * n - 1;
        while(low<=high){
            int mid = (low + high)/2;
            int row = mid/n, col = mid%n;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
};