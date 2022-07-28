class Solution {
public:
    /*
    pani at cur building  = min(leftmaxheight, rightmaxheight)\
    do it for all the buildings.
    */
    
    int trap(vector<int>& height) {
        int total = 0, n = size(height);
        int right[n];
        right[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--){
            right[i] = max(height[i], right[i+1]);
        }
        int left = height[0];
        for(int i=1; i<n-1; i++){
            if(height[i]<min(left, right[i+1])){
                total += (min(left, right[i+1]) - height[i]);
            }
            left = max(left, height[i]);
        }
        return total;
    }
};