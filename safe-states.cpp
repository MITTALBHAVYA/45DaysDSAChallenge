class Solution
{
public:
    bool dfs(int node, vector<int> &visited, vector<bool> &terminalorsafe, vector<vector<int>> &graph)
    {
        if (!visited[node])
        {
            visited[node] = true;
            if (terminalorsafe[node])
            {
                return true;
            }
            else
            {
            }
        }
        else
        {
            if (terminalorsafe[node])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<bool> terminalorsafe(n, true);
        for (auto it : graph)
        {
            for (auto i : it)
            {
                terminalorsafe[i] = false;
            }
        }
        vector<int> visited(n, false);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int check = 1;
            if (!visited[i])
            {
                if (terminalorsafe[i])
                {
                    visited[i] = true;
                    ans.push_back(i);
                }
                else
                {
                    bool valid = dfs(i, visited, terminalorsafe, graph);
                    if (valid)
                    {
                        ans.push_back(i);
                    }
                }
            }
            else
            {
                if (terminalorsafe[i])
                {
                    ans.push_back(i);
                }
            }
        }
    }
};