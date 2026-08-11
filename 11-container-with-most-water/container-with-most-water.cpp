#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            // Calculate width and minimum height between two pointers
            int width = right - left;
            int h = std::min(height[left], height[right]);
            
            // Calculate current area and update maximum water found
            int current_area = width * h;
            max_water = std::max(max_water, current_area);

            // Move the pointer pointing to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};