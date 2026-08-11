#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] will be true if s[0..i-1] matches p[0..j-1]
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        
        // Empty string matches empty pattern
        dp[0][0] = true;
        
        // Handle patterns with '*' matching an empty string (e.g., "a*", "a*b*")
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // Option 1: Treat '*' as matching 0 occurrences of the preceding element
                    bool ignore_star = dp[i][j - 2];
                    
                    // Option 2: Match current char of s if preceding char in p matches s[i-1]
                    bool match_star = (p[j - 2] == '.' || p[j - 2] == s[i - 1]) && dp[i - 1][j];
                    
                    dp[i][j] = ignore_star || match_star;
                } else {
                    // Direct character match or '.' wildcard
                    bool current_match = (p[j - 1] == '.' || p[j - 1] == s[i - 1]);
                    dp[i][j] = current_match && dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }
};