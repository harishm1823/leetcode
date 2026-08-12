#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        
        int num = 1;
        int total = n * n;

        while (num <= total) {
            // Traverse from Left to Right along the Top row
            for (int j = left; j <= right && num <= total; ++j) {
                matrix[top][j] = num++;
            }
            top++;

            // Traverse from Top to Bottom along the Right column
            for (int i = top; i <= bottom && num <= total; ++i) {
                matrix[i][right] = num++;
            }
            right--;

            // Traverse from Right to Left along the Bottom row
            for (int j = right; j >= left && num <= total; --j) {
                matrix[bottom][j] = num++;
            }
            bottom--;

            // Traverse from Bottom to Top along the Left column
            for (int i = bottom; i >= top && num <= total; --i) {
                matrix[i][left] = num++;
            }
            left++;
        }

        return matrix;
    }
};