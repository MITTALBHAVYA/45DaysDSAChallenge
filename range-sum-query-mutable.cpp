/* for better explanation visite the solution explanation 
https://leetcode.com/problems/range-sum-query-mutable/solutions/5479942/easy-solution-based-on-range-sum-query-immutable-detailed-explanation-o-nlogn/
*/
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
        int mid = low + (high-low)/2 ;
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
        int mid = low + (high-low)/2;
        int val1 = query(2*index+1,low,mid,left,right);
        int val2 = query(2*index+2,mid+1,high,left,right);
        return (val1+val2);
    }
    void newVal(int i,int low,int high,int index,int val){
        if(low==high){
            segTree[i]=val;
            return;
        }
        int mid = low + (high-low)/2;
        if(index<=mid){
            newVal(i*2+1,low,mid,index,val);
        }
        else{
            newVal(i*2+2,mid+1,high,index,val);
        }
        segTree[i]=segTree[i*2+1]+segTree[i*2+2];
        return;
    }
public:
    NumArray(vector<int>& nums) {
        arr=nums;
        build(0,0,nums.size()-1,nums);
    }
    
    void update(int index, int val) {
        newVal(0,0,arr.size()-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,arr.size()-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */