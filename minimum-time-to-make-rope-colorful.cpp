/*
https://leetcode.com/problems/minimum-time-to-make-rope-colorful/solutions/5501281/easy-solution-brute-force-80/
 */

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int left=0;
        int minCost=0;
        int count=0;
        string trial = colors+'$';
        for(int right=0;right<=n;right++){
            if(trial[left]==trial[right]){
                count++;
            }
            else{
                if(count>=2){
                    int maxi=INT_MIN;
                    int sum=0;
                    while(left<right){
                        maxi=max(maxi,neededTime[left]);
                        sum+=neededTime[left];
                        left++;
                    }
                    minCost+=(sum-maxi);
                    count=1;
                }
                else{
                    left=right;
                    count=1;
                }
            }
        }
        return minCost;
    }
};