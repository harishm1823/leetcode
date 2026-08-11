#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Map ASCII characters to their last seen index (initialized to -1)
        std::vector<int> last_seen(256, -1);
        
        int max_len = 0;
        int left = 0; // Left pointer of the sliding window
        
        for (int right = 0; right < s.length(); ++right) {
            char current_char = s[right];
            
            // If character was seen inside the current window, move the left pointer past it
            if (last_seen[current_char] >= left) {
                left = last_seen[current_char] + 1;
            }
            
            // Update last seen index of the current character
            last_seen[current_char] = right;
            
            // Calculate max window length so far
            max_len = std::max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};