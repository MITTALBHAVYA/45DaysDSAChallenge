//for detailed explanation visit
https://leetcode.com/problems/spiral-matrix/solutions/5492077/eazy-solution-100-detailed-solution/
/*

*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int>ans;
      if(matrix.size()==0 || matrix[0].size()==0){
        return ans;
      }
      int rows = matrix.size(), cols=matrix[0].size();
      int left=0,right=cols-1,top=0,bottom=rows-1;
      while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
        for(int i=right;i>=left;i--){
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;
        }
        if(left<=right){
        for(int i=bottom;i>=top;i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
        }
      }
      return ans;
    }
};