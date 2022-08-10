class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //we can use extra space and then can put back the sorted values in nums1
        //but this isn't a great idea.....
        
        //I was thinking of merging thing from forward direction
        //the approach was simple to see that if nums1[i]<nums2[i] we put it nums1[i] ahead of nums2[i]
        //but although it is failing on the test cases
        
        //so the idea is to go from backward keeping 3 pointers and then merging accordingly.
        //we keeping bigger element at last and than so on for the rest of the array.
        int i = m-1, j = n-1, k = m + n-1;
        while(i>=0 and j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }
};