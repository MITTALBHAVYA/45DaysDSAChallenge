/*
https://leetcode.com/problems/sort-array-by-increasing-frequency/solutions/5524281/easy-done-lambda-function/
*/
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>freq(201,0);
        for(auto num : nums){
            freq[num+100]++;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b){
            if(freq[a+100]==freq[b+100]){
                return a>b;
            }
            return freq[a+100]<freq[b+100];
        });
        return nums;
    }
};