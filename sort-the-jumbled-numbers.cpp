/*
https://leetcode.com/problems/sort-the-jumbled-numbers/solutions/5529905/lambda-function-interesting-way/?envType=daily-question&envId=2024-07-24
*/
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int& a, int& b) {
            int temp1 = 0, temp2 = 0;
            int mul1 = 1, mul2 = 1;
            if (a == 0) {
                temp1 = mapping[0];
            } else {
                int tempa = a;
                while (tempa) {
                    temp1 = mapping[tempa % 10] * mul1 + temp1;
                    mul1 *= 10;
                    tempa /= 10;
                }
            }
            if (b == 0) {
                temp2 = mapping[0];
            } else {
                int tempb = b;
                while (tempb) {
                    temp2 = mapping[tempb % 10] * mul2 + temp2;
                    mul2 *= 10;
                    tempb /= 10;
                }
            }
            return temp1 < temp2;
        });
        return nums;
    }
};
