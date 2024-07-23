/*
https://leetcode.com/problems/maximal-square/solutions/5524413/eazy-solution/
*/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size(),sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<mp.size();i++){
            int temp=max(i*mp[i]+sum1,sum2);
            sum1=sum2;
            sum2=temp;
        }
        return sum2;
    }
};