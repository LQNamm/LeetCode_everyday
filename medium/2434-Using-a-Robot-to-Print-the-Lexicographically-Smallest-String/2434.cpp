/**
 * Problem 2434 - Using a Robot to Print the Lexicographically Smallest String
 *
 * Note: This Problem is unuseful
 *
 * Author: Lê Quốc Nam
 * Date: 2025-06-06
 */

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        string result; 
        string t;     

        // Step 1: Compute the minimum character from index i to end of the string
        vector<char> minChar(n);
        minChar[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            minChar[i] = min(s[i], minChar[i + 1]);
        }

        // Step 2: Iterate through the string and simulate the robot operations
        for (int i = 0; i < n; ++i) {
            t.push_back(s[i]); 

            while (!t.empty() && (i == n - 1 || t.back() <= minChar[i + 1])) {
                result.push_back(t.back());
                t.pop_back();              
            }
        }

        return result; 
    }
};

