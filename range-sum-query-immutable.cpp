/*https://leetcode.com/problems/range-sum-query-immutable/solutions/5479803/easy-segment-tree-solution-detailed-explanation/ */
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class NumArray {
    public:
    int segTree[100000];
    vector<int>arr;
    void build(int index,int low,int high,vector<int>&arr){
        if(low==high){
            segTree[index]=arr[low];
            return;
        }
        int mid = low + (high - low)/2;
        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);
        segTree[index]=segTree[2*index+1]+segTree[2*index+2];
    }
    int query(int index,int low,int high,int left,int right){
        if((low>right)||(high<left)){
            return 0;
        }
        if(left<=low && right>=high){
            return segTree[index];
        }
        int mid=low + (high-low)/2;
        int val1 = query(2*index+1,low,mid,left,right);
        int val2 = query(2*index+2,mid+1,high,left,right);
        return val1+val2;
    }
public:
    NumArray(vector<int>& nums) {
        arr=nums;
        build(0,0,nums.size()-1,nums);
    }
    
    int sumRange(int left, int right) {
        int ans = query(0,0,arr.size()-1,left,right);
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */