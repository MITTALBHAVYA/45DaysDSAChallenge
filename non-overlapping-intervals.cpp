/*
https://leetcode.com/problems/non-overlapping-intervals/solutions/5500909/easay-classic-detailed-solution-94/
 */
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        
        if (n == 0) {
            return 0;
        }
        
        int count = 0;
        int end = intervals[0][1];
        
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < end) {
                count++;
                end = min(end, intervals[i][1]);
            } else {
                end = intervals[i][1];
            }
        }
        
        return count;
    }
};
