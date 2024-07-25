/*
https://leetcode.com/problems/maximum-product-subarray/solutions/5533521/solution-with-tackled-new-edge-case/
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double maxLR=INT_MIN;
        double  maxRL=INT_MIN;
        double prodLR=1;
        double prodRL=1;
        double n=nums.size();
        for(int i=0;i<n;i++){
            prodLR*=nums[i];
            prodRL*=nums[n-i-1];
            maxLR=max(maxLR,prodLR);
            maxRL=max(maxRL,prodRL);
            if(prodLR==0){
                prodLR=1;
            }
            if(prodRL==0){
                prodRL=1;
            }
        }
        return (int)max(maxLR,maxRL);
    }
};