#include <vector>
#include <algorithm>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        std::vector<int> dp(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    dp[j] = grid[0][0];
                } else if (i == 0) {
                    dp[j] = dp[j - 1] + grid[i][j]; // From left
                } else if (j == 0) {
                    dp[j] = dp[j] + grid[i][j];     // From top
                } else {
                    dp[j] = std::min(dp[j], dp[j - 1]) + grid[i][j]; // Min of top and left
                }
            }
        }

        return dp[n - 1];
    }
};