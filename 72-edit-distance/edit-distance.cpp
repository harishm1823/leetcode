#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int n = word1.length();
        int m = word2.length();

        // dp[j] will store the edit distance between word1[0...i-1] and word2[0...j-1]
        std::vector<int> dp(m + 1);

        // Base case: Converting empty word1 to word2[0...j-1] requires j insertions
        for (int j = 0; j <= m; ++j) {
            dp[j] = j;
        }

        for (int i = 1; i <= n; ++i) {
            int prev = dp[0]; // Stores top-left value dp[i-1][j-1]
            dp[0] = i;       // Base case: Converting word1[0...i-1] to empty word2 requires i deletions

            for (int j = 1; j <= m; ++j) {
                int temp = dp[j]; // Store original dp[j] before updating it

                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev; // Characters match, no operation required
                } else {
                    dp[j] = 1 + std::min({
                        dp[j],      // Delete
                        dp[j - 1],  // Insert
                        prev        // Replace
                    });
                }

                prev = temp; // Update top-left corner for the next column
            }
        }

        return dp[m];
    }
};