class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return (a[0] < b[0]);
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);
        
        int num = 0, n = properties.size();
        int attack = properties[n - 1][0], defense = properties[n - 1][1];
        
        for (int i = n - 2; i >= 0; i--) {
            if(attack > properties[i][0] and defense > properties[i][1]) {
                num++;
            }
            
            if(defense < properties[i][1]) {
                defense = properties[i][1], attack = properties[i][0];
            } 
        }
        return num;
    }
};

// [6,9] [7,10] [7,9] [7,5] [10,7] [10,4]
