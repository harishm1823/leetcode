#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::vector<int> count(128, 0);
        for (char c : t) {
            count[c]++;
        }

        int requiredCount = t.length();
        int minLen = INT_MAX;
        int minStart = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            // If character is still needed for target string t
            if (count[s[right]] > 0) {
                requiredCount--;
            }
            count[s[right]]--; // Decrement frequency count for the window

            // When valid window is found, shrink from left to find minimum length
            while (requiredCount == 0) {
                int currentLen = right - left + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    minStart = left;
                }

                count[s[left]]++;
                // If removing s[left] causes it to be missing from current valid window
                if (count[s[left]] > 0) {
                    requiredCount++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};