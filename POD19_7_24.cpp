/*
https://leetcode.com/problems/lucky-numbers-in-a-matrix/solutions/5500752/eazy-direct-solution-brute-force-98/
 */
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>rows,cols,ans;
        for(int i=0;i<m;i++){
            int mini=INT_MAX;
            for(int j=0;j<n;j++){
                mini=min(mini,matrix[i][j]);
            }
            rows.push_back(mini);
        }
        for(int i=0;i<n;i++){
            int maxi=INT_MIN;
            for(int j=0;j<m;j++){
                maxi=max(maxi,matrix[j][i]);
            }
            cols.push_back(maxi);
        }
        sort(rows.begin(),rows.end());
        sort(cols.begin(),cols.end());
        int ptr1=0,ptr2=0;
        while(ptr1<m && ptr2<n){
            if(rows[ptr1]==cols[ptr2]){
                ans.push_back(rows[ptr1]);
                ptr1++;
                ptr2++;
            }
            else if(rows[ptr1]>cols[ptr2]){
                ptr2++;
            }
            else{
                ptr1++;
            }
        }
        return ans;
    }
};