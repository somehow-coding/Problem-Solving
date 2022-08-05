class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) { 
        int maxi = 0, cnt = 0;
        for(int i=0; i<size(arr); i++){
            maxi = max(arr[i],maxi);
            if(maxi==i){
                cnt++;
            }
        }
        return cnt;
    }
};