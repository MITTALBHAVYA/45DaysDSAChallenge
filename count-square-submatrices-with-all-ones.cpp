/*
https://leetcode.com/problems/count-square-submatrices-with-all-ones/solutions/5524402/solution/
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans=0;
        vector<vector<int>>table(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            table[i][0]=matrix[i][0];
        }
        for(int i=0;i<m;i++){
            table[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int putter = min({table[i][j-1],table[i-1][j-1],table[i-1][j]});
                if(matrix[i][j])
                {table[i][j] = matrix[i][j]+putter;}
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=table[i][j];
                //cout<<table[i][j]<<" ";
            }
            //cout<<endl;
        }
        return ans;
    }
};