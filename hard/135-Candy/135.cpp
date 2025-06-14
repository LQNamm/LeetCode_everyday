/**
 * Problem 3372 - Maximize the Number of Target Nodes After Connecting Trees I
 *
 * Note: Hard problem in name only — the solution’s simple.
 *
 * Author: Lê Quốc Nam
 * Date: 2025-06-02
 */ 

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }v
        }

        // right to left
        int sum = candies[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }

        return sum;
    }
};

