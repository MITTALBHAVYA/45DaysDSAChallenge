/*
https://leetcode.com/problems/unique-paths/solutions/5530152/mathmatics/
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int totalsteps = m-1 + n-1;
        int bottomsteps = m-1;
        if(bottomsteps==0 || totalsteps==bottomsteps){
            return 1;
        }
        double ans = 0;
        for(int i=0;i<bottomsteps;i++){
            ans += log(totalsteps-i)-log(i+1);
        }
        return (int)round(exp(ans));
    }
};