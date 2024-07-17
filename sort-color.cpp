
/*
for detailed explanation visit
https://leetcode.com/problems/sort-colors/solutions/5492322/three-pointers-classic-question-100-o-n/
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int high=nums.size()-1;
        int low=0,mid=0;
        while(mid<=high)
        {
            switch(nums[mid])
            {
                case 0:swap(nums[low++],nums[mid++]);
                    break;
                case 1:mid++;
                    break;
                case 2:swap(nums[high--],nums[mid]);
                    break;
            }
        }
    }
};