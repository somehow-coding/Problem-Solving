var maxProductDifference = function(nums) {
    nums.sort(function(a, b){return a - b});
    for(let x of nums) console.log(x);
    let n = nums.length;
    return (nums[n-1]*nums[n-2]) - (nums[1]*nums[0]);
};