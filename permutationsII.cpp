/*
for detailed explanation refer to the link below
https://leetcode.com/problems/permutations-ii/solutions/5485539/eazy-solution-detailed-solution-built-in-function/
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums);
        while(next_permutation(nums.begin(), nums.end())){
            ans.push_back(nums);
        }
        return ans;
    }
};