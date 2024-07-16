/*
for detailed explanation refer to the link below
https://leetcode.com/problems/subsets/solutions/5485519/itterative-approach-detailed-explanation/
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans={{}};
        for(auto num : nums){
            int n = ans.size();
            for(int i=0;i<n;i++){
                ans.push_back(ans[i]);
                ans.back().push_back(num);
            }
        }
        return ans;
    }
};