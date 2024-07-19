/*
https://leetcode.com/problems/split-array-largest-sum/solutions/5503086/100-detailed-solution-eazy-approach/
 */
class Solution {
public:
    bool solve(vector<int>&nums, int mid, int n,int k){
        int part=1;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(sum+nums[i] > mid){
                part++;
                sum = nums[i];
                if(part>k || nums[i]>mid){
                    return false;
                }
            }
            else{
                sum+=nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int low = 0;
        int high = sum;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2 ;
            if(solve(nums,mid,n,k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};