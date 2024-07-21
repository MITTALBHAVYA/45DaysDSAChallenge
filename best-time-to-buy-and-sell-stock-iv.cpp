/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/post-solution/?submissionId=1328643851
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(!n)return 0;
        vector<int>buy(k,INT_MAX);
        vector<int>profit(k,INT_MIN);
        for(auto price : prices){
            buy[0]=min(buy[0],price);
            profit[0]=max(profit[0],price-buy[0]);
            for(int i=1;i<k;i++){
                buy[i]=min(buy[i],(price-profit[i-1]));
                profit[i]=max(profit[i],price-buy[i]);
            }
        }
        return profit[k-1];
    }
};