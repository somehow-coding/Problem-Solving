class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int j = 0, i = 0;
        while(i<size(firstList) and j<size(secondList)){
            if(firstList[i][0]>secondList[j][1]){
                j++;
            }
            else if(firstList[i][1]<secondList[j][0]){
                i++;
            }
            else if(firstList[i][1]>=secondList[j][1]){
                res.push_back({max(firstList[i][0],secondList[j][0]), min(firstList[i][1],secondList[j][1])});
                j++;
            }
            else if(secondList[j][1]>firstList[i][1]){
                res.push_back({max(firstList[i][0],secondList[j][0]), min(firstList[i][1],secondList[j][1])});
                i++;
            }
            
        }
        return res;
    }
};