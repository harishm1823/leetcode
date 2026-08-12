#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            count[nums[right]]++;

            // Shrink window if the frequency of the current element exceeds k
            while (count[nums[right]] > k) {
                count[nums[left]]--;
                left++;
            }

            // Update the maximum subarray length
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};