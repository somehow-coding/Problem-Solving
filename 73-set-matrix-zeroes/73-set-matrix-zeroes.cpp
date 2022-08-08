class Solution {
public:
    //first approach which i'm thinking about is to store rows and columns number in some map or set
    //like data structure and then traversing the matrix, and at each element we see that for this 
    //element if either row or col contains zero(by looking in data structure) if that's the case 
    //we make the element zero.
    
    //time complexity and space complexity for the above approach
    //tc: O(m*n)
    //space: O(m+n)
    
    //we can do better in space
    //if we encounter any zero we make that column's and row's first element as zero
    //edge case to be handled in case of first row and first col.....
    //what is edge case???
    //see we are setting every first element of the row and col to zero and suppose 
    //it happened that we set matrix[0][0] = 0 for first row(index = 0), then we also set 
    //the whole first col to be zero because we see that for the first col we have first element
    //as zero but that is not the right case.
    
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_row = false, first_col = false;
        for(int row=0; row<size(matrix); row++){
            for(int col=0; col<size(matrix[0]); col++){
                if(matrix[row][col]==0){
                    //set first element as zero for both row and col
                    if(row and col){
                        matrix[row][0] = 0;
                        matrix[0][col] = 0;
                    }
                    //handling the edge case
                    if(row==0){
                        first_row = true;
                    }
                    if(col==0){
                        first_col = true;
                    }
                }
            }
        }
        int row=1, col=1;
        for(; row<size(matrix);row++){
            if(matrix[row][0]==0){
                for(int j=1;j<size(matrix[0]); j++){
                    matrix[row][j] = 0;
                }
            }
        }
        for(; col<size(matrix[0]); col++){
            if(matrix[0][col]==0){
                for(int i=1;i<size(matrix);i++){
                    matrix[i][col] = 0;
                }
            }
        }
        if(first_row){
            for(int j=0;j<size(matrix[0]); j++){
                matrix[0][j] = 0;
            }
        }
        if(first_col){
            for(int i=0;i<size(matrix);i++){
                matrix[i][0] = 0;
            }
        }
    }
};