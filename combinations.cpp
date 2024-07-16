/*
for detailed explanation refer to the link below
https://leetcode.com/problems/combinations/solutions/5485560/eazy-solution-detailed-solution/
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int>set;
    vector<vector<int>>superset;
    void solve(int n,int k){
        if(set.size()==k){
            superset.push_back(set);
            return;
        }
        if(n==0){
            return;
        }
        set.push_back(n);
        solve(n-1,k);
        set.pop_back();
        solve(n-1,k);
    }
    vector<vector<int>> combine(int n, int k) {
        solve(n,k);
        return superset;
    }
};