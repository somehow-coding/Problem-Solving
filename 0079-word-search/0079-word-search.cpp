class Solution {
public:
    int m, n, l;
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    bool fun(vector<vector<char>> &mat, string &s, int index, int row, int col) {
        if(index==l) {
            return true;
        }
        if(row>=m or row<0 or col<0 or col>=n or mat[row][col]!=s[index]) {
            return 0;
        }
        
        int r, c;
        char ch = mat[row][col];
        mat[row][col] = '$';
        for(int i=0;i<4;i++) {
            r = row + dir[i][0], c = col + dir[i][1];
            if(fun(mat, s, index+1, r, c)) return true;
        }
        mat[row][col] = ch;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size(), l = word.size();
        for(int i=0;i<m; i++) {
            for(int j=0; j<n;j++) {
                if(fun(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};