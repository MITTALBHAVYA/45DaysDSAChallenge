/* for better explanation visite the solution explanation 
https://leetcode.com/problems/remove-k-digits/solutions/5495762/easy-greedy-missing-the-last-case-the-special-case/
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (auto digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int index = 0;
        while (index < ans.size() && ans[index] == '0') {
            index++;
        }
        string newString = ans.substr(index);
        return newString.empty() ? "0" : newString;
    }
};
