/*
https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/solutions/5506112/eazy-solution-greedy-brute-force/
*/
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int have = rowSum[i];
            for(int j=0;j<m;j++){
                ans[i][j]=min(colSum[j],have);
                have-=ans[i][j];
                colSum[j]-=ans[i][j];
            }
        }
        return ans;
    }
};