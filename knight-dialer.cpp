/*
https://leetcode.com/problems/knight-dialer/solutions/5533437/good-question/
*/
class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int remains,vector<vector<int>>&moves,vector<vector<int>>&dp){
       for(int i=0;i<10;i++){
        dp[0][i]=1;
       }
       for(int remain=1;remain<remains;remain++){
        for(int at=0;at<10;at++){
            int ans=0;
            for(auto i : moves[at]){
                ans = (ans + dp[remain-1][i])%mod;
            }
            dp[remain][at]=ans;
        }
       }
       int ans=0;
       for(int at=0;at<10;at++){
        ans = (ans+dp[remains-1][at])%mod;
       }
       return ans;
    }
    int knightDialer(int n) {
        vector<vector<int>>moves={
            {4,6},
            {6,8},
            {7,9},
            {4,8},
            {0,3,9},
            {},
            {0,7,1},
            {2,6},
            {1,3},
            {2,4}
        };
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(10,0));
        ans = (ans + solve(n,moves,dp))%mod;
        return ans;
    }
};