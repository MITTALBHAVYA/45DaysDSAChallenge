//for detailed explanation visit
https://leetcode.com/problems/longest-repeating-character-replacement/solutions/5492299/eazy-solution-detailed-solution-two-pointers-o-26-n/
/*

*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int n =s.size();
        int left=0,right=0,count=0;
        for(char ch='A';ch<='Z';ch++){
            left=0;
            right=0;
            count=0;
            while(right<n){
                if(s[right]==ch){
                    right++;
                }
                else if(count<k){
                    right++;
                    count++;
                }
                else if(s[left]==ch){
                    left++;
                }
                else{
                    left++;
                    count--;
                }
                ans=max(ans,right-left);
            }
        }
        return ans;
    }
};