class Solution {
    unordered_map<int, vector<int>> graph; // Graph adjacency list
    vector<int> discoveryTime, lowTime; // Discovery and low times of nodes
    vector<vector<int>> criticalEdges; // List to store critical connections

public:
    void dfs(int currentNode, int parentNode, int& currentTime) {
        currentTime++; // Increment the current time
        discoveryTime[currentNode] = currentTime; // Set the discovery time for the current node
        lowTime[currentNode] = currentTime; // Set the low time for the current node

        for (int neighbor : graph[currentNode]) {
            if (neighbor == parentNode) continue; // Skip the parent node
            if (discoveryTime[neighbor] == -1) { // Check if neighbor is not visited
                dfs(neighbor, currentNode, currentTime);
                lowTime[currentNode] = min(lowTime[currentNode], lowTime[neighbor]);

                // If the lowest reachable vertex from the neighbor is greater than the discovery time of the current node, it's a critical connection
                if (lowTime[neighbor] > discoveryTime[currentNode]) {
                    criticalEdges.push_back({currentNode, neighbor});
                }
            } else {
                lowTime[currentNode] = min(lowTime[currentNode], discoveryTime[neighbor]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Build the graph from the list of connections
        graph.clear();
        for (const auto& connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }

        discoveryTime.assign(n, -1); // Initialize discovery times with -1 (unvisited)
        lowTime.assign(n, -1); // Initialize low times
        criticalEdges.clear(); // Clear previous results if any

        int currentTime = 0; // Time counter for DFS

        // Start DFS from each unvisited node
        for (int i = 0; i < n; ++i) {
            if (discoveryTime[i] == -1) {
                dfs(i, -1, currentTime);
            }
        }

        return criticalEdges; // Return the list of critical connections
    }
};
