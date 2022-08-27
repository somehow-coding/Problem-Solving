class Solution {
public:
    /*
    water at cur building  = min(leftmaxheight, rightmaxheight)
    do it for all the buildings.
    */
    
    int trap(vector<int>& height) {
        /*
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
        */
        //above approch will need extra O(n) space 
        
        // more optimal approach used 2 pointers
        
        // in this approach maintains two values left_max and right_max
        // and traverse the array using two pointers.
        int left_max = 0, right_max = 0, left = 0, right = height.size()-1;
        int water_trapped = 0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(left_max<height[left]){
                    left_max = height[left];
                }
                else{
                    /**how part???*/
                    //how are we sure that there exists a height which is 
                    //greater than or equal to left_max is that if it wasn't 
                    //there we might not have reached here at the cur height.
                    //so there must be a greate height on right than only we 
                    // are able to move from left most height to uptil now(left)
                    water_trapped += (left_max-height[left]);
                }
                left++;
            }
            else{
                if(right_max<height[right]){
                    right_max = height[right];
                }
                else{
                    /**how part??? is cleared above*/
                    water_trapped += (right_max-height[right]);
                }
                right--;
            }
        }
        return water_trapped;
    }
};