/*
https://leetcode.com/problems/maximum-product-of-three-numbers/solutions/5503149/easy-sorting-o-nlogn-detailed-solution/
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
    }
};