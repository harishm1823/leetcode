class Solution {
private:
    // Helper function to find the first or last occurrence of target
    int findBound(const vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int bound = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    right = mid - 1; // Keep searching on the left side
                } else {
                    left = mid + 1;  // Keep searching on the right side
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return bound;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);

        // If target is not present, no need to perform second search
        if (first == -1) {
            return {-1, -1};
        }

        int last = findBound(nums, target, false);

        return {first, last};
    }
};