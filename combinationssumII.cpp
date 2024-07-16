/*
for detailed explanation refer to the link below
https://leetcode.com/problems/combination-sum-ii/solutions/5485554/eazy-solution-backtracking-detailed-solution/
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> combination;

    void dfs(int start, int target, vector<int>& candidates) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            combination.push_back(candidates[i]);
            dfs(i + 1, target - candidates[i], candidates);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, target, candidates);
        return result;
    }
};
