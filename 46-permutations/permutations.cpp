#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(int first, std::vector<int>& nums, std::vector<std::vector<int>>& result) {
        if (first == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = first; i < nums.size(); ++i) {
            std::swap(nums[first], nums[i]);
            backtrack(first + 1, nums, result);
            std::swap(nums[first], nums[i]); // Backtrack
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }
};