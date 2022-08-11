class Combinations{
    public:
    int N;
    int T;
    int sum;
    set<vector<int>> container;
    vector<vector<int>> combinations;
    vector<int> combination;
};

class Solution {
public:
    void findList(Combinations &C, vector<int> &candidates, int index){        
        if(index==C.N){
            if(C.sum!=C.T){
                return;
            }
            vector<int> temp = C.combination;
            sort(begin(temp),end(temp));
            if(!C.container.count(temp)){
                C.combinations.push_back(temp);
                C.container.insert(temp);
            }
            return;
        }
        
        findList(C, candidates, index+1);
        
        if(C.sum + candidates[index] > C.T){
            return;
        }
        C.combination.push_back(candidates[index]);
        C.sum += candidates[index];
        findList(C, candidates, index);
        C.combination.pop_back();
        C.sum -= candidates[index];
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        Combinations C;
        C.N = size(candidates), C.T = target, C.sum = 0;
        findList(C, candidates, 0);
        return C.combinations;
    }
};