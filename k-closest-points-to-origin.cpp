/*
https://leetcode.com/problems/k-closest-points-to-origin/solutions/5538067/sare-tag-dal-diye-for-reach/
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        vector<vector<int>>ans;
        for(int i=0;i<points.size();i++){
            pq.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            int index = pq.top().second;
            pq.pop();
            ans.push_back(points[index]);
        }
        return ans;
    }
};