/*
https://leetcode.com/problems/minimum-moves-to-equal-array-elements/solutions/5501622/greedy-approach-maths-set-theory-out-of-the-box-logical-analysis/
*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(nums[i]-mini);
        }
        return ans;
    }
};