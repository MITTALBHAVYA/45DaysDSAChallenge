/*
https://leetcode.com/problems/swim-in-rising-water/solutions/5538565/eazy-solution/
*/
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<int>dir={0,0,-1,1};
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int n = grid.size();
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int elevation=it[0];
            int X = it[1];
            int Y = it[2];
            int present_value = grid[X][Y];
            if(grid[X][Y]==-1){
                continue;
            }
            if(X==n-1 && Y==n-1){
                return elevation;
            }
            grid[X][Y]=-1;
            for(int i=0;i<4;i++){
                int newX = X+dir[i];
                int newY = Y+dir[3-i];
                if(newX>=0 && newY>=0 && newX<n && newY<n && grid[newX][newY]!=-1){
                    pq.push({max(elevation,grid[newX][newY]),newX,newY});
                }
            }
        }
        return 0;
    }
};