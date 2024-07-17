/*
https://leetcode.com/problems/maximum-number-of-visible-points/solutions/5492572/very-hard-at-first-glance-took-help-of-hints-maths-knowledge-required/
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int visiblePoints(std::vector<std::vector<int>>& points, int angle,vector<int>& location) {
        int duplicatepoints = 0;
        vector<double> radians;
        for (auto point : points) {
            if (point[0] == location[0] && point[1] == location[1]) {
                duplicatepoints++;
            } else {
                double radian = atan2(point[1] - location[1], point[0] - location[0]) * 180.0 / M_PI;
                if (radian < 0) {
                    radian += 360;
                }
                radians.push_back(radian);
            }
        }
        
        vector<double> all_radians = radians;
        for (double radian : radians) {
            all_radians.push_back(radian + 360);
        }
        
        sort(all_radians.begin(), all_radians.end());
        
        int max_count = 0;
        int left = 0;
        for (int right = 0; right < all_radians.size(); right++) {
            while (all_radians[right] - all_radians[left] > angle) {
                left++;
            }
            max_count = max(max_count, right - left + 1);
        } 
        return duplicatepoints + max_count;
    }
};
