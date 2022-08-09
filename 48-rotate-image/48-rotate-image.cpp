class Solution {
public:
    
    //doing it by recursion
    void fun(vector<vector<int>> &matrix, int i, int j, int I, int J){
        if(i>=I or j>=J){
            return;
        }
        for(int c=0; c<(J-j); c++){
            int val1 = matrix[i+c][J];
            matrix[i+c][J] = matrix[i][j+c];
            int val2 = matrix[I][J-c];
            matrix[I][J-c] = val1;
            int val3 = matrix[I-c][j];
            matrix[I-c][j] = val2;
            matrix[i][j+c] = val3;
        }
        fun(matrix, i+1,j+1,I-1,J-1);
    }
    
    void rotate(vector<vector<int>>& matrix) {
        fun(matrix,0,0,size(matrix)-1,size(matrix)-1);
    }
};