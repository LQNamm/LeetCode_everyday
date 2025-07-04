/**
 * Problem 3372 - Maximize the Number of Target Nodes After Connecting Trees I
 *
 * Note: Use BFS or DFS to find the depth
 *
 * Author: Lê Quốc Nam
 * Date: 2025-05-28
 */

class Solution {
public:
    vector<int> bfsReachableCounts(const vector<vector<int>>& edges, int k) {
        // 1. Build adjacency list
        int n = edges.size() + 1;
        
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); 
        }

        // 2. use BFS to find depth for each Node
        vector<int> result(n);

        for (int start = 0; start < n; ++start) {
            vector<bool> visited(n, false);
            queue<pair<int, int>> q;
            q.push({start, 0});
            visited[start] = true;

            int count = 1;

            while (!q.empty()) {
                int v = q.front().first;
                int depth = q.front().second;
                q.pop();

                if (depth >= k) continue;

                for (int neighbor : adj[v]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({neighbor, depth + 1});
                        count++;
                    }
                }
            }

            result[start] = count;
        }

        return result;
    }
   
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int> reachable1 = bfsReachableCounts(edges1, k);

        if(k != 0){
            vector<int> reachable2 = bfsReachableCounts(edges2, k - 1);
            // find max of reachable2
            int maxR2 = *max_element(reachable2.begin(), reachable2.end());
            // sum the depth of reachable2 to each Node of reachable1
            for (int& x : reachable1) {
                x += maxR2;
            }
        }
        return reachable1;
    }
};
