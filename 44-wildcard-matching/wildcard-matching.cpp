#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sIdx = 0, pIdx = 0;
        int starIdx = -1, matchIdx = 0;

        while (sIdx < s.length()) {
            // Case 1: Characters match or '?' matches any single character
            if (pIdx < p.length() && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            }
            // Case 2: '*' matches zero or more characters
            else if (pIdx < p.length() && p[pIdx] == '*') {
                starIdx = pIdx;
                matchIdx = sIdx;
                pIdx++;
            }
            // Case 3: Last character didn't match, but we saw a '*' earlier -> backtrack
            else if (starIdx != -1) {
                pIdx = starIdx + 1;
                matchIdx++;
                sIdx = matchIdx;
            }
            // Case 4: No match and no '*' to fallback on
            else {
                return false;
            }
        }

        // Consume remaining '*' in pattern
        while (pIdx < p.length() && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == p.length();
    }
};