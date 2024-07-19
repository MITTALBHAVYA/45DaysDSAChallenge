/* for better explanation visite the solution explanation 
https://leetcode.com/problems/task-scheduler/solutions/5496057/greedy-approach-detailed-solution-upvote-please/
*/
#include <bits/stdc++.h>
#include <vector>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26]={0};
        int maxCount=0;
        for(char task : tasks){
            freq[task-'A']++;
            maxCount = max(maxCount,freq[task-'A']);
        }
        int time = (maxCount-1)*(n+1);
        for(int i : freq){
            if(i==maxCount){
                time++;
            }
        }
        return max((int)tasks.size(),time);
    }
};