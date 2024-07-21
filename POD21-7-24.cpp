/*
https://leetcode.com/problems/build-a-matrix-with-conditions/post-solution/?submissionId=1328008767
*/
class Solution {
public:
    vector<int>topologicalSort(vector<vector<int>>&edges,int n){
        vector<vector<int>>adjGraph(n+1);
        vector<int>deg(n+1);
        vector<int>ans;
        for(auto x : edges){
            adjGraph[x[0]].push_back(x[1]);
            deg[x[1]]++;
        }
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(deg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            n--;
            for(auto neigh : adjGraph[node]){
                deg[neigh]--;
                if(deg[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        if(n!=0){
            return {};
        }
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>rows = topologicalSort(rowConditions,k);
        vector<int>cols = topologicalSort(colConditions,k);
        if(rows.empty() || cols.empty()){
            return {};
        }
        vector<vector<int>>matrix(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(rows[i]==cols[j]){
                    matrix[i][j]=rows[i];
                }
            }
        }
        return matrix;
    }
};