class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_zeroes = 0, count_twos = 0;
        for(int i=0; i<size(nums); i++){
            if(nums[i]==0){
                ++count_zeroes;
            }
            else if(nums[i]==2){
                ++count_twos;
            }
            nums[i] = 1;
        }
        int left = 0;
        while(count_zeroes--){
            nums[left++] = 0;
        }
        int right = size(nums)-1;
        while(count_twos--){
            nums[right--] = 2;
        }
    }
};