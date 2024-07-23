/*
https://leetcode.com/problems/longest-increasing-subsequence/solutions/5524409/solution/
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>sub;
        for(auto x:nums){
            if(sub.empty() || sub[sub.size()-1]<x){
                sub.push_back(x);
            }
            else{
                auto it= lower_bound(sub.begin(),sub.end(),x);
                *it=x;
            }
        }
        return sub.size();
    }
};
