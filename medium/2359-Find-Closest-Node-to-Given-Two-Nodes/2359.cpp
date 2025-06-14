/**
 * Problem 2359 - Find Closest Node to Given Two Nodes
 *
 * Note: Use BFS or DFS to find the depth
 *
 * Author: Lê Quốc Nam
 * Date: 2025-05-30
 */

class Solution {
public:
    vector<int> bfsDepths(const vector<int>& edges, int start) {
        int n = edges.size();
        vector<int> depth(n, -1); // -1 mean not reachable
        queue<int> q;

        depth[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            int v = edges[u];
            if (v != -1 && depth[v] == -1) { // if has edge and not visit
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }

        return depth;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> depth1 = bfsDepths(edges,node1);
        vector<int> depth2 = bfsDepths(edges,node2);
        
        int result = -1;
        int minDistance = INT_MAX;

        for (int i = 0; i < edges.size(); ++i) {
            if (depth1[i] != -1 && depth2[i] != -1) {
                if (max(depth1[i] , depth2[i]) < minDistance) {
                    minDistance = max(depth1[i] , depth2[i]);
                    result = i;
                }
            }
        }
        return result;
    }
};