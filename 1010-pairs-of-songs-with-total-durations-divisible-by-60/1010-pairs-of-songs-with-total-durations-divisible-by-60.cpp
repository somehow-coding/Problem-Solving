class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& arr) {
        map<int, int> m;
    long long p = 0;
    m[60] = -1;
    for (int x : arr) {
        int val = 60 - (x % 60);
        if (val == 60) {
            if (m[val] == -1) {
                m[val] = 0;
            } else {
                p += m[val];
            }
            m[val]++;
        } else {
            p += m[val];
            m[x % 60] += 1;
        }
    
    }
        return p;
    }
};