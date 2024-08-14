class Solution {
public:
    int dfs(int node,vector<vector<int>>&adjGraph,vector<int>&no_of_nodes_in_subtree,vector<int>&visited,int sumwithzero,int level){
        visited[node]=1;
        sumwithzero += level;
        int no_of_child=0;
        for(auto neigh : adjGraph[node]){
            if(!visited[neigh]){
                no_of_child += dfs(neigh,adjGraph,no_of_nodes_in_subtree,visited,sumwithzero,level+1);
            }
        }
        return no_of_nodes_in_subtree[node] = no_of_child + 1;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjGraph(n);
        for(int i=0;i<n-1;i++){
            adjGraph[edges[i][0]].push_back(edges[i][1]);
            adjGraph[edges[i][1]].push_back(edges[i][0]);
        }
        int level=0;
        int sumwithzero=0;
        vector<int>no_of_nodes_in_subtree(n,0);
        vector<int>visited(n,0);
        vector<int>ans;
        int temp = dfs(0,adjGraph,no_of_nodes_in_subtree,visited,sumwithzero,level);
        cout<<"Children"<<endl;
        for(auto it : no_of_nodes_in_subtree){
            cout<<it<<" ";
        }
        cout<<endl;
        return ans;
    }
};