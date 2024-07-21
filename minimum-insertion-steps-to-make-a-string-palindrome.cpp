/*
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/post-solution/?submissionId=1328617466
*/
class Solution {
public:
    int solve(string &s,int start,int end,vector<vector<int>>&dp){
        if(start>=s.size() || end<0){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int ans=0;
        if(s[start]==s[end]){
            ans = 1 + solve(s,start+1,end-1,dp);
        }
        else{
            ans = max(solve(s,start+1,end,dp),solve(s,start,end-1,dp));
        }
        return dp[start][end]=ans;
    }
    int minInsertions(string s) {
        int count=0;
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        count=solve(s,0,n-1,dp);
        return s.size()-count;
    }
};