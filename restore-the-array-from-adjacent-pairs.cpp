/* for better explanation visite the solution explanation 
https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/solutions/5496558/easy-believe-your-instincts-upvote-please/
*/
#include <bits/stdc++.h>
#include <vector>
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        unordered_map<int,vector<int>>mp;
        for(auto& i : adjacentPairs){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        int start = 0;
        for(auto& i : mp){
            if(i.second.size()==1){
                start=i.first;
                break;
            }
        }
        vector<int>ans = {start};
        int prev = INT_MAX;
        while(ans.size()<mp.size()){
            for(int neigh : mp[start]){
                if(neigh != prev){
                    ans.push_back(neigh);
                    prev=start;
                    start=neigh;
                    break;
                }
            }
        }
        return ans;
    }
};