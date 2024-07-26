/*
https://leetcode.com/problems/minimum-cost-to-hire-k-workers/solutions/5538256/eazy-solution/
*/
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>>wage_per_quality;
        for(int i=0;i<n;i++){
            double x = (double)wage[i]/quality[i];
            wage_per_quality.push_back({x,quality[i]});
        }
        double ans=INT_MAX;
        sort(wage_per_quality.begin(),wage_per_quality.end());
        priority_queue<int>pq;
        double totalquality=0;
        for(int i=0;i<n;i++){
            pq.push(wage_per_quality[i].second);
            totalquality+=wage_per_quality[i].second;
            if(pq.size()>k){
                totalquality-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans = min(ans,totalquality*wage_per_quality[i].first);
            }
        }
        return ans;
    }
};