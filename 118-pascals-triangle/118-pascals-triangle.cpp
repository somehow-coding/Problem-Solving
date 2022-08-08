class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // if(numRows==1) return {{1}};
        // vector<vector<int>> ret;
        // ret.push_back({1});
        // ret.push_back({1,1});
        // for(int row = 2; row<numRows; row++){
        //     vector<int> cur(row+1,1);
        //     for(int i=1; i<row; i++){
        //         cur[i] = ret[row-1][i-1] + ret[row-1][i];
        //     }
        //     ret.push_back(cur);
        // }
        // return ret;
        
        vector<vector<int>> res;
        //size(res) is fixed
        //size(res[row]) is not fixed so we need a temporary vector.
        for(int row=0; row<numRows;row++){
            vector<int> temp(row+1,1);
            for(int col=1;col<row;col++){
                temp[col] = res[row-1][col-1] + res[row-1][col];
            }
            res.push_back(temp);
        }
        return res;
    }
};