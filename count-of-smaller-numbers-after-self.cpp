/*
for detailed solution visit this link : 
https://leetcode.com/problems/count-of-smaller-numbers-after-self/solutions/5480200/policy-based-data-structure-easy-solution-ordered-set-red-black-treee/
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <vector>
using namespace __gnu_pbds;
using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> PBDS;
        PBDS sorted_set;
        for (int i = n - 1; i >= 0; --i) {
            counts[i] = sorted_set.order_of_key(make_pair(nums[i], i));
            sorted_set.insert(make_pair(nums[i], i));
        }

        return counts;
    }
};
