#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

// Define ordered_set
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        ordered_set od;
        for (int i = 0; i < k; i++) {
            od.insert({nums[i], i});
        }
        ans.push_back(od.find_by_order(k - 1)->first);

        for (int i = k; i < n; i++) {
            od.erase({nums[i - k], i - k});
            od.insert({nums[i], i});
            ans.push_back(od.find_by_order(k - 1)->first);
        }

        return ans;
    }
};