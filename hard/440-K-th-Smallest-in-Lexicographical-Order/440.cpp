/**
 * Problem 440 - K-th Smallest in Lexicographical Order
 *
 * Note: slove Problem 386 - Lexicographical Numbers before do this Problem
 *
 * Author: Lê Quốc Nam
 * Date: 2025-05-09
 */

class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        k -= 1;  //  curr = 1 is the first not curr = 0

        while (k > 0) {
            long steps = countSteps(curr, n);
            if (steps <= k) {
                curr++;      // skip this branch
                k -= steps;
            } else {
                curr *= 10;  // go deeper in branch
                k -= 1;      // skip this curr
            }
        }

        return (int)curr;
    }

    long countSteps(long curr, int n) {
        long next = curr + 1;
        long steps = 0;
        while (curr <= n) {
            steps += min((long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};
