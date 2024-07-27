class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long INF = LLONG_MAX;
        vector<vector<long long>> grid(26, vector<long long>(26, INF));
        for (int i = 0; i < 26; i++) {
            grid[i][i] = 0;
        }
        int n = original.size();
        for (int i = 0; i < n; i++) {
            grid[original[i] - 'a'][changed[i] - 'a'] = min((long long)cost[i], grid[original[i] - 'a'][changed[i] - 'a']);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (grid[i][k] != INF && grid[k][j] != INF) {
                        grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                    }
                }
            }
        }
        if (source.size() != target.size()) {
            return -1;
        }
        long long ans = 0;
        int m = source.size();
        for (int i = 0; i < m; i++) {
            if (grid[source[i] - 'a'][target[i] - 'a'] == INF) {
                return -1;
            }
            ans += grid[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};
