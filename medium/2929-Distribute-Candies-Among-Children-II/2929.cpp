/**
 * Problem 2929 - Distribute Candies Among Children II
 *
 * Note: You must use one loop to pass this problem
 *
 * Author: Lê Quốc Nam
 * Date: 2025-06-01
 */

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long total = 0;
        for (int i = 0; i <= min(n, limit); ++i) {
            int rest = n - i;
            int j_min = max(0, rest - limit);
            int j_max = min(limit, rest);
            if (j_min <= j_max) {
                total += (j_max - j_min + 1); // số lượng j hợp lệ
            }
        }
        return total;
    }
};
