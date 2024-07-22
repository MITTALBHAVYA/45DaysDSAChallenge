/*
https://leetcode.com/problems/sort-the-people/solutions/5518694/pod/
*/
class Solution {
public:
    static bool cmp(pair<string,int>&a,pair<string,int>&b){
        return a.second>b.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<string,int>>vect;
        for(int i=0;i<n;i++){
            vect.push_back({names[i],heights[i]});
        }
        sort(vect.begin(),vect.end(),cmp);
        vector<string>ans;
        for(int i=0;i<n;i++){
            ans.push_back(vect[i].first);
        }
        return ans;
    }
};