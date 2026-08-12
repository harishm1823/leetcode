#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);

            // When reaching the end of the current jump reach,
            // make a jump to extend the reach to the farthest reachable index.
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                
                // Early exit if we can already reach the end
                if (currentEnd >= n - 1) break;
            }
        }

        return jumps;
    }
};