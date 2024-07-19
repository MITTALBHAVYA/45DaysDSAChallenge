/*

*/
class Solution {
public:
    int solve(int low, int high, vector<int>& nums) {
        int mid = low + (high - low) / 2;
        
        if (low > high) {
            return -1;
        }
        
        if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
            return mid;
        } else if (mid > 0 && nums[mid - 1] > nums[mid]) {
            return solve(low, mid - 1, nums);
        } else {
            return solve(mid + 1, high, nums);
        }
    }
    
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        if (high == 0) {
            return 0;
        } else if (high == 1) {
            if (nums[0] > nums[1]) {
                return 0;
            }
            return 1;
        } else {
            return solve(low, high, nums);
        }
    }
};