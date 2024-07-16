/*
here is the detailed solution
https://leetcode.com/problems/beautiful-arrangement/solutions/5485459/eaazy-solution-good-approach-backtracking/
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int dfs(vector<bool>&visited,int index){
        if(index==0){
            return 1;
        }
        int ans=0;
        for(int i=1;i<visited.size();i++){
            if(visited[i]==0 && (index%i==0 || i%index==0)){
                visited[i]=index;
                ans+=dfs(visited,index-1);
                visited[i]=0;
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<bool>visited(n+1,0);
        return dfs(visited,n);
    }
};
