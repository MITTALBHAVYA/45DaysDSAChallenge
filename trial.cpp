class Solution
{
public:
    int solve(int low, int high, vector<int> &nums, int target)
    {
        if (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[high] == target)
            {
                return high;
            }
            if (nums[low] == target)
            {
                return low;
            }
            if (nums[low] > target && nums[high] < target)
            {
                return -1;
            }
            if (nums[mid] < target)
            {
                if (nums[low] < target && nums[high] < target)
                {
                    return max(solve(low + 1, mid - 1, nums, target), solve(mid + 1, high - 1, nums, target));
                }
                low = mid + 1;
                high--;
                return solve(low, high, nums, target);
            }
            if (nums[mid] > target)
            {
                if (nums[low] > target && nums[high] > target)
                {
                    return max(solve(low + 1, mid - 1, nums, target), solve(mid + 1, high - 1, nums, target));
                }
                low++;
                high = mid - 1;
                return solve(low, mid, nums, target);
            }
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans = solve(low, high, nums, target);
        return ans;
    }
};