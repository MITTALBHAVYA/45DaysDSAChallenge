/*
https://leetcode.com/problems/decode-ways/solutions/5530584/easy/
*/

class Solution {
public:
    int solve(string &s,int index,vector<int>&dp){
        if(dp[index]!=0){
            return dp[index];
        }
        if(index>=s.size()){
            return 1;
        }
        else if(s[index]=='0'){
            return 0;
        }
        else if(index==s.size()-1){
            return 1;
        }
        else if(s[index]=='1' || (s[index]=='2' && (s[index+1]>='0' && s[index+1]<='6'))){
            return dp[index]=solve(s,index+1,dp)+solve(s,index+2,dp);
        }
        else{
            return dp[index]=solve(s,index+1,dp);
        }
    }
    int numDecodings(string s) {
        int index=0;
        vector<int>dp(s.size()+1,0);
        return solve(s,index,dp);
    }
};
