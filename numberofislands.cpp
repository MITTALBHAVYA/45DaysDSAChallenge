/*
https://leetcode.com/problems/number-of-islands/solutions/5556423/eazy-solution/
*/
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || grid[i][j]=='0'){
            return;
        }
        else{
            grid[i][j]='0';
            dfs(grid,i+1,j);
            dfs(grid,i-1,j);
            dfs(grid,i,j+1);
            dfs(grid,i,j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};