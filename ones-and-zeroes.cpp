/*
https://leetcode.com/problems/ones-and-zeroes/submissions/1332931440/
*/
class Solution {
public:
    int solve(vector<string>& strs,int index,int m,int n,vector<vector<vector<int>>>&dp){
        if(index>=strs.size()){
            return 0;
        }
        if(dp[index][m][n]!=-1){
            return dp[index][m][n];
        }
        string check = strs[index];
        int ones=0,zeros=0;
        for(auto ch : check){
            if(ch=='1'){
                ones++;
            }
            else{
                zeros++;
            }
        }
        int ans=0;
        if(m-zeros<0 || n-ones<0){
            ans = solve(strs,index+1,m,n,dp);
        }
        else{
            int a = 1 + solve(strs,index+1,m-zeros,n-ones,dp);
            int b = solve(strs,index+1,m,n,dp);
            ans = max(a,b);
        }
        return dp[index][m][n]=ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int ans = solve(strs,0,m,n,dp);
        return ans;
    }
};