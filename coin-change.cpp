/*

*/
class Solution {
public:
    int solve(vector<int>& coins, int index, int amount, vector<vector<int>>& dp) {
        // Base cases
        if (amount == 0) return 0; // No coins needed to make amount 0
        if (index >= coins.size() || amount < 0) return INT_MAX - 1; // Invalid case

        if (dp[index][amount] != INT_MAX) {
            return dp[index][amount];
        }

        int ans;
        if (coins[index] > amount) {
            // Skip this coin
            ans = solve(coins, index + 1, amount, dp);
        } else {
            // Include this coin or skip it
            int include = 1 + solve(coins, index, amount - coins[index], dp);
            int exclude = solve(coins, index + 1, amount, dp);
            ans = min(include, exclude);
        }

        return dp[index][amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, INT_MAX));
        int ans = solve(coins, 0, amount, dp);
        return (ans == INT_MAX-1) ? -1 : ans;
    }
};
