#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> result;
        if (matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse from Left to Right along the Top row
            for (int j = left; j <= right; ++j) {
                result.push_back(matrix[top][j]);
            }
            top++;

            // Traverse from Top to Bottom along the Right column
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--;

            // Traverse from Right to Left along the Bottom row
            if (top <= bottom) {
                for (int j = right; j >= left; --j) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // Traverse from Bottom to Top along the Left column
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};