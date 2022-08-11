class Solution {
public:
    
    /*
    map to bana hi skte hai...
    sort bhi kar skte hai and then check...
    but both are not that optimal...
    */
    //values 1 to n nhi hai nhi to thoda kuch soch skte the(bi).

    // boyer-moore majority vote algorithm is optimal approach.
        
    int majorityElement(vector<int>& nums) {
        // boyer-moore majority vote algorithm.
        int cur_element = nums[0], cur_freq = 0;
        for(int num: nums){
            //element changes.
            if(cur_freq==0){
                cur_element = num;
                cur_freq = 1;
            }
            else{
                if(cur_element==num){
                    cur_freq++;
                }
                else{
                    cur_freq--;
                }
            }
        }
        return cur_element;
    }
};