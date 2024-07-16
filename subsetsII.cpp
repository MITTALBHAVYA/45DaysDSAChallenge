/*
for detailed explanation refer to the link below
https://leetcode.com/problems/subsets-ii/solutions/5485499/eazy-solution-backtracking-array-detailed-solution/
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    set<vector<int>>s;
    vector<int>v;
    void dfs(int i,vector<int>& nums){
        if(i==nums.size()){
            s.insert({v});
            return;
        }
        v.push_back(nums[i]);
        dfs(i+1,nums);
        v.pop_back();
        dfs(i+1,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        dfs(0,nums);
        ans.assign(s.begin(),s.end());
        return ans;
    }
};