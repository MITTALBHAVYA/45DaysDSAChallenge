/*https://leetcode.com/problems/counting-bits/solutions/5533476/easy-solution/*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++){
            ans[i] = ans[i>>1] + (i&1);
        }
        return ans;
    }
};