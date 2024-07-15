/* for detailed explanation refer to the following link
https://leetcode.com/problems/count-of-range-sum/solutions/5480342/policy-based-data-structure-easy-solution-detailed-solution/
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class Solution {
public:
    tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long count=0;
        vector<long long>prefix(nums.size());
        long long pre=0;
        for(int i=0;i<nums.size();i++){
            prefix[i]=pre + nums[i] ;
            pre=prefix[i];
        }
        ordered_set.insert(0);
        for(auto it : prefix){
            count+=ordered_set.order_of_key(it-lower+1)- ordered_set.order_of_key(it-upper);
            ordered_set.insert(it);
        }
        return (int)count;
    }
};