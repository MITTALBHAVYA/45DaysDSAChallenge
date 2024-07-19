/*
https://leetcode.com/problems/palindrome-pairs/solutions/5501541/easy-approach-detailed-solution/
*/

class Solution {
public:
    bool isPalindrome(string& str){
        int start=0,end=str.size()-1;
        while(start<end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            string temp = words[i];
            reverse(temp.begin(),temp.end());
            mp[temp]=i;
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            string temp=words[i];
            for(int j = 0; j<=temp.size();j++){
                string suf = temp.substr(j);
                string pre = temp.substr(0,j);
                if(!pre.empty() && isPalindrome(pre) && mp.count(suf)!=0 && mp[suf]!=i){
                    ans.push_back({mp[suf],i});
                }
                if(isPalindrome(suf) && mp.count(pre)!=0 && mp[pre]!=i){
                    ans.push_back({i,mp[pre]});
                }
            }
        }
        return ans;
    }
};