/*
here is the detailed solution
https://leetcode.com/problems/palindrome-partitioning/solutions/5485476/easy-solution-backtracking-dfs-detailed-approach/
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>>ans;
    vector<string>temp;
    bool isPalindrome(string &s,int low,int high){
        while(low<high){
            if(s[low]!=s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    void dfs(int start,string &s){
        if(start>=s.size()){
            ans.push_back(temp);
        }
        for(int i=start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
                temp.push_back(s.substr(start,i-start+1));
                dfs(i+1,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(0,s);
        return ans;
    }
};