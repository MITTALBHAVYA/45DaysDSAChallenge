/*
https://leetcode.com/problems/maximal-rectangle/solutions/5517400/matrix-is-love-find-pattern-you-will-get-it/
*/
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            grid[i][0] = matrix[i][0] - '0';
        }
        for (int i = 0; i < m; i++)
        {
            grid[0][i] = matrix[0][i] - '0';
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    grid[i][j] = min({grid[i][j - 1], grid[i - 1][j], grid[i - 1][j - 1]}) + 1;
                }
            }
        }
        int ans = 0;
        int areaX = 0, areaY = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    areaX = grid[i][j] * grid[i][j];
                    areaY = areaX;
                    for (int x = i + 1; x < n; x++)
                    {
                        if (grid[i][j] <= grid[x][j] && grid[x][j])
                        {
                            areaX += grid[i][j];
                        }
                        else
                        {
                            break;
                        }
                    }
                    for (int y = j + 1; y < m; y++)
                    {
                        if (grid[i][j] <= grid[i][y] && grid[i][y])
                        {
                            areaY += grid[i][j];
                        }
                        else
                        {
                            break;
                        }
                    }
                    ans = max({areaX, areaY, ans});
                }
            }
        }
        return ans;
    }
};