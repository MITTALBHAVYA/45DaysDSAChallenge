/*
https://leetcode.com/problems/search-in-rotated-sorted-array/solutions/5503295/detailed-solution-explanation-binary-search/
*/
class Solution {
public:
    int solve(vector<int>& nums, int low, int high, int target) {
        if (low > high) {
            return -1;
        }
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                return solve(nums, low, mid - 1, target);
            } else {
                return solve(nums, mid + 1, high, target);
            }
        }
        else {
            if (nums[mid] < target && target <= nums[high]) {
                return solve(nums, mid + 1, high, target);
            } else {
                return solve(nums, low, mid - 1, target);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return solve(nums, 0, nums.size() - 1, target);
    }
};
