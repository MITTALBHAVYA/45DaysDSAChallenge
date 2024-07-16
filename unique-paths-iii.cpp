/*
here is the detailed solution
https://leetcode.com/problems/unique-paths-iii/solutions/5484161/easy-solution-detailed-explanation-dfs-must-watch/
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int dfs(int x,int y,pair<int,int>&end,int remains,vector<vector<int>>& grid){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==-1){
            return 0;
        }
        if(x==end.first && y==end.second){
            if(remains==-1){
                return 1;
            }
            else{
                return 0;
            }
        }
        grid[x][y]=-1;
        remains--;
        int ans = dfs(x-1,y,end,remains,grid)
                + dfs(x+1,y,end,remains,grid)
                + dfs(x,y+1,end,remains,grid)
                + dfs(x,y-1,end,remains,grid) ;
        grid[x][y]=0;
        remains++;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int,int>start,end;
        int totalMoves=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    totalMoves++;
                }
                if(grid[i][j]==1){
                    start.first=i;
                    start.second=j;
                }
                if(grid[i][j]==2){
                    end.first=i;
                    end.second=j;
                }
            }
        }
        int ans = dfs(start.first,start.second,end,totalMoves,grid);
        return ans;
    }
};