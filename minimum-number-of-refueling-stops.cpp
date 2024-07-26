/*
https://leetcode.com/problems/minimum-number-of-refueling-stops/solutions/5538416/eazy-solution/
*/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel>=target){
            return 0;
        }
        priority_queue<int>pq;
        int index=0;
        int n = stations.size();
        int possible=0;
        int maxi = startFuel;
        while(maxi<target){
            while(index < n && stations[index][0]<=maxi){
                pq.push(stations[index][1]);
                index++;
            }
            if(pq.empty()){
                return -1;
            }
            maxi+=pq.top();
            pq.pop();
            possible++;
        }
        return possible;
    }
};