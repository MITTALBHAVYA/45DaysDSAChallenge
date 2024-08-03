/*
https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/solutions/5556327/eazy-o-n-easy-no-dp-no-stack/
*/
class Solution {
public:
    int minimumDeletions(string s) {
        int b_count = 0;
        int deletions = 0;

        for (char& ch : s) {
            if (ch == 'b') {
                b_count++;
            } else if (ch == 'a') {
                if (b_count > 0) {
                    deletions++;
                    b_count--;
                }
            }
        }
        return deletions;
    }
};
