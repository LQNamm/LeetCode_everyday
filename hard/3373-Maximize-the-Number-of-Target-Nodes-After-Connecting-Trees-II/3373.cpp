/**
 * Problem 3372 - Maximize the Number of Target Nodes After Connecting Trees I
 *
 * Note: Use BFS or DFS to find the depth and color it
 *
 * Author: Lê Quốc Nam
 * Date: 2025-05-29
 */

 class Solution {
public:
    void bfsColoring(int start, vector<vector<int>>& adj, vector<int>& colors) {
        queue<int> q;
        q.push(start);
        colors[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (colors[neighbor] == -1) {
                    colors[neighbor] = 1 - colors[node];
                    q.push(neighbor);
                }
            }
        }
    }

    vector<int> evenReachable(const vector<vector<int>>& edges) {
        // 1. Build adjacency list
        int n = edges.size() + 1;

        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); // 
        }

        vector<int> colors(n, -1); // -1 for not colored, 0 & 1 is 2 color
        for (int i = 0; i < n; ++i) {
            if (colors[i] == -1) {
                bfsColoring(i, adj, colors); 
            }
        }

        // Cound Node has color 0 & 1
        int countColor0 = 0, countColor1 = 0;
        for (int c : colors) {
            if (c == 0) countColor0++;
            else if (c == 1) countColor1++;
        }

        // The nodes that have the same color as it are exactly the nodes that have even distance
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = (colors[i] == 0 ? countColor0 : countColor1);
        }

        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> even1 = evenReachable(edges1);
        vector<int> even2 = evenReachable(edges2);

        int maxEven2 = *max_element(even2.begin(), even2.end());

        for (int& x : even1) {
            x += maxEven2;
        }

        return even1;
    }
};
