/**
 * Problem 386 - Lexicographical Numbers
 *
 * Note: slove this with DFS
 *
 * Author: Lê Quốc Nam
 * Date: 2025-05-08
 */

lass Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int curr = 1;

        for (int i = 0; i < n; i++) {
            result.push_back(curr);
            
            if (curr * 10 <= n) {
                // go deeper
                curr *= 10;
            } else {
                // if can't go deeper
                while (curr % 10 == 9 || curr + 1 > n) {
                    curr /= 10;
                }
                curr++;
            }
        }

        return result;
    }
};
