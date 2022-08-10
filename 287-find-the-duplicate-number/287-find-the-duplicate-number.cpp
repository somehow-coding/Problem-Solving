class Solution {
public:
    /*
    There are many approaches to the problem:
    
    ..approach one:
    we can use set or map to store values and return value which repeats.
    but this using constant extra space.
    
    
    //this below appraoches won't work as duplicate element can be any no of times.
    //they might have worked it only one element is repeated only twice.
    ..approach two:
    we know numbers will be from 1 to n for sure we do xor for 1 to n and then xor the values of the array
    and when you xor the 2 values you get the duplicate number.
    
    ..approach three:
    as we know the numbers will be from 1 to n we can sum 1 to n and than subtract it from the sum of
    values of the array.
    
    there is one more approach which is O(nlogn) in tc which is using binary search......
    */
    
    /*
    O(N) approach:
    the intution is such that we keeping visiting elements and for that element we do nums[element-1],
    multiply by -1 so that if we visit same element twice we know the element will at that index will
    become positive.
    */
    
    int findDuplicate(vector<int>& nums) {
        //approach: multiplying with -1.
        int duplicate = -1;
        for(int i=0; i<size(nums);i++){
            int j = abs(nums[i]) - 1;
            nums[j] = -1 * nums[j];
            if(nums[j]>0){
                duplicate = abs(nums[i]);
                break;
            }
        }
        
        //reverting back the changes we have made in the array(we can't modify the nums)
        for(int i=0;i<size(nums); i++){
            if(nums[i]<0){
                nums[i] = -1 * nums[i];
            }
        }
        return duplicate;
    }
};