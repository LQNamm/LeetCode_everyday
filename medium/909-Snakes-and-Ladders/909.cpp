/**
 * Problem 3372 - Maximize the Number of Target Nodes After Connecting Trees I
 *
 * Note: Use BFS or DFS to find the depth count the step
 *
 * Author: Lê Quốc Nam
 * Date: 2025-05-31
 */

 
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> arr = build(board);
        return bfs(arr);
    }

private:
    // Change zigzag matrix to 1D array
    vector<int> build(const vector<vector<int>>& board) {
        int n = board.size();
        vector<int> arr(n * n + 1); // 1-based index
        int idx = 1;
        bool leftToRight = true;

        for (int row = n - 1; row >= 0; --row) {
            if (leftToRight) {
                for (int col = 0; col < n; ++col) {
                    arr[idx++] = board[row][col];
                }
            } else {
                for (int col = n - 1; col >= 0; --col) {
                    arr[idx++] = board[row][col];
                }
            }
            leftToRight = !leftToRight;
        }
        return arr;
    }

    // BFS to find min step
    int bfs(const vector<int>& arr) {
        int n = static_cast<int>(sqrt(arr.size() - 1));
        vector<bool> visited(arr.size(), false);
        queue<pair<int, int>> q; // {posision, step}
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [pos, steps] = q.front(); // = pos = q.f.first; steps = q.f.second;
            q.pop();
            if (pos == n * n) return steps;

            for (int move = 1; move <= 6 && pos + move <= n * n; ++move) {
                int next = pos + move;
                if (arr[next] != -1) next = arr[next];
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }
        return -1;
    }
};

