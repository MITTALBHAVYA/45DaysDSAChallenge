/*
https://leetcode.com/problems/second-minimum-time-to-reach-destination/solutions/5549020/hard-i-serously-took-help-of-editorial/
*/
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adjGraph(n + 1);
        for (auto &edge : edges) {
            adjGraph[edge[0]].push_back(edge[1]);
            adjGraph[edge[1]].push_back(edge[0]);
        }
        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX), freq(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.push({0, 1});
        dist1[1] = 0;
        while (!min_heap.empty()) {
            auto it = min_heap.top();
            min_heap.pop();
            freq[it.second]++;
            if (freq[it.second] == 2 && it.second == n) {
                return it.first;
            }
            if ((it.first / change) % 2) {
                it.first = change * ((it.first / change) + 1) + time;
            } else {
                it.first += time; 
            }

            for (auto &neigh : adjGraph[it.second]) {
                if (freq[neigh] == 2) {
                    continue;
                }
                if (dist1[neigh] > it.first) {
                    dist2[neigh] = dist1[neigh];
                    dist1[neigh] = it.first;
                    min_heap.push({dist1[neigh], neigh});
                } else if (dist2[neigh] > it.first && dist1[neigh] != it.first) {
                    dist2[neigh] = it.first;
                    min_heap.push({dist2[neigh], neigh});
                }
            }
        }
        return 0;
    }
};
