class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        for(int i=1; i<=n;i++){
            v.push_back(i);
        }
        for(int i=1;i<k;i++){
            next_permutation(begin(v),end(v));
        }
        string s="";
        for(int i: v) s += ('0' + i);
        return s;
    }
};