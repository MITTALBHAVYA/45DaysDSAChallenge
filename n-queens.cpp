/*
for detailed explanation visit the link
https://leetcode.com/problems/n-queens/solutions/5484285/eazy-solution-detailed-explanation-upvote-please-backtracking/
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<string>>&ans,vector<string>&board,vector<int>&leftRow,vector<int>&lowerDiagonal,vector<int>&upperDiagonal,int col){
        if(col==board.size()){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<board.size();row++){
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[board.size()-1+col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[board.size()-1+col-row]=1;
                dfs(ans,board,leftRow,lowerDiagonal,upperDiagonal,col+1);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[board.size()-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>board(n,s);
        vector<int>leftRow(n,0),lowerDiagonal(2*n -1,0),upperDiagonal(2*n -1,0);
        dfs(ans,board,leftRow,lowerDiagonal,upperDiagonal,0);
        return ans;
    }
};