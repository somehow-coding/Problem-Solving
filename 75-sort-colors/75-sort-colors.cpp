class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int count_zeroes = 0, count_twos = 0;
        // for(int i=0; i<size(nums); i++){
        //     if(nums[i]==0){
        //         ++count_zeroes;
        //     }
        //     else if(nums[i]==2){
        //         ++count_twos;
        //     }
        //     nums[i] = 1;
        // }
        // int left = 0;
        // while(count_zeroes--){
        //     nums[left++] = 0;
        // }
        // int right = size(nums)-1;
        // while(count_twos--){
        //     nums[right--] = 2;
        // }
        
        /*
        one-pass algorithm:
        */
        
        // setting up 0 and 2
        
        int ptr0=0, ptr1=0, ptr2=size(nums)-1;
        while(ptr1<=ptr2){
            if(nums[ptr1]==0 and ptr1==ptr0){
                ptr1++;
                continue;
            }
            if(nums[ptr1]==0){
                swap(nums[ptr1],nums[ptr0]);
                ptr0++;
                continue;
            }
            if(nums[ptr1]==2){
                swap(nums[ptr2],nums[ptr1]);
                ptr2--;
                continue;
            }
            if(nums[ptr1]==1){
                ptr1++;
            }
        }
    }
};