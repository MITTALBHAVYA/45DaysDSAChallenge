/*
https://leetcode.com/problems/super-egg-drop/solutions/5516795/eazy-solution-detailed-approach-use-classic-intutives/
*/

class Solution {
public:
    int superEggDrop2(int eggs, int floors,vector<vector<int>>&dp){
        int mini = INT_MAX;
        if(eggs==1 || floors<=1){
            return floors;
        }
        if(dp[eggs][floors]!=-1){
            return dp[eggs][floors];
        }
        int low = 0,high =floors;
        while(low<=high){
            int mid = low + (high-low)/2;
            int left = superEggDrop2(eggs-1,mid-1,dp);
            int right = superEggDrop2(eggs,floors-mid,dp);
            if(left<right){
                low = mid+1;
            }
            else{
                high=mid-1;
            }
            mini=min(mini,1+max(left,right));
        }
        return dp[eggs][floors]=mini;
    }
    int superEggDrop(int eggs, int floors) {
        vector<vector<int>>dp(eggs+1,vector<int>(floors+1,-1));
        return superEggDrop2(eggs,floors,dp);
    }
};